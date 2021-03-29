#pragma once
#include "componentlibrary.hpp"
#include "random.hpp"
#include <vector>
#include <jansson.h>
#include <iostream>

using namespace std;

namespace rack {


struct BidooRoundBlackSnapKnob : RoundBlackSnapKnob {
	BidooRoundBlackSnapKnob() {
		setSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/BlackKnobBidoo.svg")));
		shadow->opacity = 0.0f;
	}
};

struct BidooRoundBlackKnob : RoundBlackKnob {
	BidooRoundBlackKnob() {
		setSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/BlackKnobBidoo.svg")));
		shadow->opacity = 0.0f;
	}
};

struct BidooBlueKnob : RoundKnob {
	BidooBlueKnob() {
		setSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/BlueKnobBidoo.svg")));
		shadow->opacity = 0.0f;
	}
};

struct BidooGreenKnob : RoundKnob {
	BidooGreenKnob() {
		setSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/GreenKnobBidoo.svg")));
		shadow->opacity = 0.0f;
	}
};

struct BidooRedKnob : RoundKnob {
	BidooRedKnob() {
		setSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/RedKnobBidoo.svg")));
		shadow->opacity = 0.0f;
	}
};

struct BidooHugeBlueKnob : RoundKnob {
	BidooHugeBlueKnob() {
		setSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/HugeBlueKnobBidoo.svg")));
		shadow->opacity = 0.0f;
	}
};

struct BidooLargeBlueKnob : RoundKnob {
	BidooLargeBlueKnob() {
		setSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/LargeBlueKnobBidoo.svg")));
		shadow->opacity = 0.0f;
	}
};

struct BidooSmallBlueKnob : RoundKnob {
	BidooSmallBlueKnob() {
		setSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/SmallBlueKnobBidoo.svg")));
		shadow->opacity = 0.0f;
	}
};

struct BidooSmallSnapBlueKnob : RoundBlackSnapKnob {
	BidooSmallSnapBlueKnob() {
		setSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/SmallBlueKnobBidoo.svg")));
		shadow->opacity = 0.0f;
	}
};

struct BidooBlueSnapKnob : RoundBlackSnapKnob  {
	BidooBlueSnapKnob() {
		setSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/BlueKnobBidoo.svg")));
		shadow->opacity = 0.0f;
	}
};

struct BidooBlueSnapTrimpot : Trimpot  {
	BidooBlueSnapTrimpot() {
		setSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/BlueTrimpotBidoo.svg")));
		snap = true;
		smooth = false;
		shadow->opacity = 0.0f;
	}
};

struct BidooBlueTrimpot : Trimpot {
	BidooBlueTrimpot() {
		setSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/BlueTrimpotBidoo.svg")));
		shadow->opacity = 0.0f;
	}
};

struct BlueCKD6 : app::SvgSwitch {
	BlueCKD6() {
		momentary = true;
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/BlueCKD6_0.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/BlueCKD6_1.svg")));
		shadow->opacity = 0.0f;
	}
};

struct BlueBtn : app::SvgSwitch {
	std::string caption;
	shared_ptr<Font> font;

	BlueBtn() {
		momentary = true;
		font = APP->window->loadFont(asset::plugin(pluginInstance,"res/DejaVuSansMono.ttf"));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/BlueBtn_0.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/BlueBtn_1.svg")));
		shadow->opacity = 0.0f;
	}

	void draw(const DrawArgs &args) override {
		SvgSwitch::draw(args);
		nvgFontSize(args.vg, 12.0f);
		nvgFontFaceId(args.vg, font->handle);
		nvgTextAlign(args.vg, NVG_ALIGN_CENTER);
		nvgText(args.vg, 8.0f, 12.0f, (caption).c_str(), NULL);
	}
};

struct RedBtn : app::SvgSwitch {
	std::string caption;
	shared_ptr<Font> font;

	RedBtn() {
		momentary = true;
		font = APP->window->loadFont(asset::plugin(pluginInstance,"res/DejaVuSansMono.ttf"));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/RedBtn_0.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/RedBtn_1.svg")));
		shadow->opacity = 0.0f;
	}

	void draw(const DrawArgs &args) override {
		SvgSwitch::draw(args);
		nvgFontSize(args.vg, 12.0f);
		nvgFontFaceId(args.vg, font->handle);
		nvgTextAlign(args.vg, NVG_ALIGN_CENTER);
		nvgText(args.vg, 8.0f, 12.0f, (caption).c_str(), NULL);
		//nvgStroke(args.vg);
	}
};

struct MuteBtn : app::SvgSwitch {
	MuteBtn() {
		momentary = true;
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/MuteBtn_0.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/MuteBtn_1.svg")));
		shadow->opacity = 0.0f;
	}
};

struct SoloBtn : app::SvgSwitch {
	SoloBtn() {
		momentary = true;
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/SoloBtn_0.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/SoloBtn_1.svg")));
		shadow->opacity = 0.0f;
	}
};

struct LeftBtn : app::SvgSwitch {
	LeftBtn() {
		momentary = true;
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/LeftBtn_0.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/LeftBtn_1.svg")));
		shadow->opacity = 0.0f;
	}
};

struct RightBtn : app::SvgSwitch {
	RightBtn() {
		momentary = true;
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/RightBtn_0.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/RightBtn_1.svg")));
		shadow->opacity = 0.0f;
	}
};

struct UpBtn : app::SvgSwitch {
	UpBtn() {
		momentary = true;
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/UpBtn_0.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/UpBtn_1.svg")));
		shadow->opacity = 0.0f;
	}
};

struct DownBtn : app::SvgSwitch {
	DownBtn() {
		momentary = true;
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/DownBtn_0.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/DownBtn_1.svg")));
		shadow->opacity = 0.0f;
	}
};

struct BidooColoredKnob : RoundKnob {
	BidooColoredKnob() {
		setSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/ColoredKnobBidoo.svg")));
		shadow->opacity = 0.0f;
	}
};

struct BidooMorphKnob : RoundKnob {
	BidooMorphKnob() {
		setSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/SpiralKnobBidoo.svg")));
		shadow->opacity = 0.0f;
	}
};

struct BidooColoredTrimpot : RoundKnob {
	NSVGshape *tShape = NULL;

	BidooColoredTrimpot() {
		minAngle = -0.75f*M_PI;
		maxAngle = 0.75f*M_PI;
		setSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/TrimpotBidoo.svg")));
		shadow->opacity = 0.0f;
	}
};

struct BidooziNCColoredKnob : RoundKnob {
	float *coeff = NULL;
	float corrCoef = 0;
	NSVGshape *tShape = NULL;

	BidooziNCColoredKnob() {
		setSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/BlueKnobBidoo.svg")));
		box.size = Vec(28, 28);
		shadow->opacity = 0.0f;
	}
};

struct BidooSlidePotLong : app::SvgSlider {
	BidooSlidePotLong() {
		snap = true;
		maxHandlePos = Vec(0.0f, 0.0f);
		minHandlePos = Vec(0.0f, 84.0f);
		background->svg = APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/bidooSlidePotLong.svg"));
		background->wrap();
		background->box.pos = Vec(0.0f, 0.0f);
		box.size = background->box.size;
		handle->svg = APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/bidooSlidePotHandle.svg"));
		handle->wrap();
	}

	void randomize() override {
		random::init();
  	paramQuantity->setValue(roundf(rescale(random::uniform(), 0.0f, 1.0f, paramQuantity->getMinValue(), paramQuantity->getMaxValue())));
  }
};

struct BidooSlidePotShort : app::SvgSlider {
	BidooSlidePotShort() {
		snap = true;
		maxHandlePos = Vec(0.0f, 0.0f);
		minHandlePos = Vec(0.0f, 60.0f);
		background->svg = APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/bidooSlidePotShort.svg"));
		background->wrap();
		background->box.pos = Vec(0.0f, 0.0f);
		box.size = background->box.size;
		handle->svg = APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/bidooSlidePotHandle.svg"));
		handle->wrap();
	}

	void randomize() override {
		random::init();
  	paramQuantity->setValue(roundf(rescale(random::uniform(), 0.0f, 1.0f, paramQuantity->getMinValue(), paramQuantity->getMaxValue())));
  }
};

struct CKSS8 : app::SvgSwitch {
	CKSS8() {
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/CKSS8_0.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/CKSS8_1.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/CKSS8_2.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/CKSS8_3.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/CKSS8_4.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/CKSS8_5.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/CKSS8_6.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/CKSS8_7.svg")));
		sw->wrap();
		box.size = sw->box.size;
		shadow->opacity = 0.0f;
	}
};

struct CKSS4 : app::SvgSwitch {
	CKSS4() {
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/CKSS4_0.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/CKSS4_1.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/CKSS4_2.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/CKSS4_3.svg")));
		sw->wrap();
		box.size = sw->box.size;
		shadow->opacity = 0.0f;
	}
};

struct TinyPJ301MPort : app::SvgPort {
	TinyPJ301MPort() {
		// background->svg = APP->window->loadSvg(asset::system("res/ComponentLibrary/TinyPJ301M.svg"));
		// background->wrap();
		setSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/TinyPJ301M.svg")));
		shadow->opacity = 0.0f;
	}
};

struct MiniLEDButton : app::SvgSwitch {
	MiniLEDButton() {
		momentary = true;
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ComponentLibrary/miniLEDButton.svg")));
		shadow->opacity = 0.0f;
	}
};

} // namespace rack
