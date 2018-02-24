#include "Bidoo.hpp"
#include "dsp/digital.hpp"
#include "BidooComponents.hpp"
#include <curl/curl.h>
#include <thread>
#include <mpg123.h>
#include "dsp/ringbuffer.hpp"
#include "dsp/frame.hpp"
#include <algorithm>
#include <cctype>
#include <atomic>

using namespace std;

std::atomic<bool> tPlay(true);
std::atomic<bool> tFree(true);

struct threadData {
  mpg123_handle *mh;
  DoubleRingBuffer<Frame<2>,262144> *dataRingBuffer;
  string url;
  int bytes;
  int channels;
  int encoding;
  long rate;
};


size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
  struct threadData *pData = (struct threadData *) userp;
  size_t realsize = size * nmemb;
  off_t frame_offset;
  size_t done;
  size_t i;
  int err;
  unsigned char *audio;
  mpg123_feed(pData->mh, (const unsigned char*) contents, realsize);
  do {
      err = mpg123_decode_frame(pData->mh, &frame_offset, &audio, &done);
      switch(err) {
          case MPG123_NEW_FORMAT:
              mpg123_getformat(pData->mh, &pData->rate, &pData->channels, &pData->encoding);
              pData->bytes = mpg123_encsize(pData->encoding);
              break;
          case MPG123_OK:
              i = 0;
              do {
                Frame<2> newFrame;
                unsigned char l[] = {audio[i+0], audio[i+1], audio[i+2], audio[i+3]};
                memcpy(&newFrame.samples[0], &l, sizeof(newFrame.samples[0]));
                unsigned char r[] = {audio[i+4], audio[i+5], audio[i+6], audio[i+7]};
                memcpy(&newFrame.samples[1], &r, sizeof(newFrame.samples[1]));
                pData->dataRingBuffer->push(newFrame);
                i += 8;
              }
              while(i < done);
              break;
          case MPG123_NEED_MORE:
              break;
          default:
              break;
      }
  } while(done > 0);
  return tPlay.load() ? realsize : 0;
}

void * threadTask(threadData data)
{
  // struct threadData *pData;
  // pData = (struct threadData *) data;
  tFree.store(false);
  CURL *curl;
  curl = curl_easy_init();
  curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
  curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
  curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
  curl_easy_setopt(curl, CURLOPT_URL, data.url.c_str());
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
  curl_easy_perform(curl);
  curl_easy_cleanup(curl);
  tFree.store(true);
  return 0;
}

struct ANTN : Module {
	enum ParamIds {
		URL_PARAM,
		TRIG_PARAM,
    GAIN_PARAM,
		NUM_PARAMS
	};
	enum InputIds {
		NUM_INPUTS
	};
	enum OutputIds {
		OUTL_OUTPUT,
		OUTR_OUTPUT,
		NUM_OUTPUTS
	};
	enum LightIds {
		NUM_LIGHTS
	};
  string url;
	SchmittTrigger trigTrigger;
  size_t index = 0;
  bool read = false;
  DoubleRingBuffer<Frame<2>,262144> dataRingBuffer;
  mpg123_handle *mh = NULL;
  int bytes = 0;
  int channels = 0;
  int encoding = 0;
  long rate;
  thread rThread;
  threadData tData;
  bool first = true;

	ANTN() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS) {
    mpg123_init();
    mh = mpg123_new(NULL, NULL);
    mpg123_format_none(mh);
    mpg123_format(mh, engineGetSampleRate(), 2, MPG123_ENC_FLOAT_32);
    mpg123_open_feed(mh);
    tData.mh = mh;
    tData.dataRingBuffer = &dataRingBuffer;
	}

  ~ANTN() {
    if (!tFree.load()) {
      tPlay.store(false);
    }
    mpg123_close(mh);
    mpg123_delete(mh);
    mpg123_exit();
  }

  json_t *toJson() override {
    json_t *rootJ = json_object();
    json_object_set_new(rootJ, "url", json_string(url.c_str()));
    return rootJ;
  }

  void fromJson(json_t *rootJ) override {
    json_t *urlJ = json_object_get(rootJ, "url");
  	if (urlJ)
  		url = json_string_value(urlJ);
  }

	void step() override;
};


void ANTN::step() {
	if (trigTrigger.process(params[TRIG_PARAM].value)) {
    if (!tFree.load()) {
      tPlay.store(false);
      while(!tFree) {
      }
    }
    tData.url = url;
    tPlay.store(true);
    rThread = thread(threadTask, std::ref(tData));
    rThread.detach();
	}

  if (dataRingBuffer.size()>200000) {
    read = true;
  }

  if (read) {
    Frame<2> currentFrame = *dataRingBuffer.startData();
    outputs[OUTL_OUTPUT].value = 10*currentFrame.samples[0]*params[GAIN_PARAM].value;
    outputs[OUTR_OUTPUT].value = 10*currentFrame.samples[1]*params[GAIN_PARAM].value;
    dataRingBuffer.startIncr(1);
  }
}

struct ANTNTextField : TextField {
  ANTNTextField(ANTN *mod) {
    module = mod;
  }
	void onTextChange() override;
	ANTN *module;
};
void ANTNTextField::onTextChange() {
	if (text.size() > 0) {
      string tText = text;
      tText.erase(std::remove_if(tText.begin(), tText.end(), [](unsigned char x){return std::isspace(x);}), tText.end());
      module->url = tText;
	}
}


ANTNWidget::ANTNWidget() {
	ANTN *module = new ANTN();
	setModule(module);
	box.size = Vec(15*9, 380);

	{
		SVGPanel *panel = new SVGPanel();
		panel->box.size = box.size;
		panel->setBackground(SVG::load(assetPlugin(plugin, "res/ANTN.svg")));
		addChild(panel);
	}

	textField = new ANTNTextField(module);
	textField->box.pos = Vec(5, 25);
	textField->box.size = Vec(125, 100);
	textField->multiline = true;
	addChild(textField);

	addChild(createScrew<ScrewSilver>(Vec(15, 0)));
	addChild(createScrew<ScrewSilver>(Vec(box.size.x-30, 0)));
	addChild(createScrew<ScrewSilver>(Vec(15, 365)));
	addChild(createScrew<ScrewSilver>(Vec(box.size.x-30, 365)));

  addParam(createParam<BidooBlueKnob>(Vec(54, 183), module, ANTN::GAIN_PARAM, 0.5f, 3.0f, 1.0f));

	addParam(createParam<BlueCKD6>(Vec(54, 245), module, ANTN::TRIG_PARAM, 0.0f, 1.0f, 0.0f));

	static const float portX0[4] = {34, 67, 101};

	addOutput(createOutput<TinyPJ301MPort>(Vec(portX0[1]-17, 334), module, ANTN::OUTL_OUTPUT));
	addOutput(createOutput<TinyPJ301MPort>(Vec(portX0[1]+4, 334), module, ANTN::OUTR_OUTPUT));
}

json_t *ANTNWidget::toJson() {
	json_t *rootJ = ModuleWidget::toJson();

	// text
	json_object_set_new(rootJ, "text", json_string(textField->text.c_str()));

	return rootJ;
}

void ANTNWidget::fromJson(json_t *rootJ) {
	ModuleWidget::fromJson(rootJ);

	// text
	json_t *textJ = json_object_get(rootJ, "text");
	if (textJ)
		textField->text = json_string_value(textJ);
}
