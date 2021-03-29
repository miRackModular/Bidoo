#include "plugin.hpp"


Plugin *pluginInstance;

void init(rack::Plugin *p) {
	pluginInstance = p;

	p->addModel(modelTOCANTE);
	p->addModel(modelLATE);
	// p->addModel(modelDIKTAT); //poly
	p->addModel(modelDTROY);
	p->addModel(modelBORDL);
	p->addModel(modelZOUMAI);
	p->addModel(modelMU);
  p->addModel(modelCHUTE);
	p->addModel(modelLOURDE);
	p->addModel(modelACNE);
	p->addModel(modelMS);
	p->addModel(modelDUKE);
	p->addModel(modelMOIRE);
	p->addModel(modelHUITRE);
	p->addModel(modelOUAIVE);
	// p->addModel(modelPOUPRE); //poly
	// p->addModel(modelMAGMA); //poly
	// p->addModel(modelOAI); //poly
	p->addModel(modelCANARD);
	p->addModel(modelEMILE);
	p->addModel(modelFORK);
	p->addModel(modelTIARE);
	p->addModel(modelCLACOS);
	// p->addModel(modelANTN); //libcurl
	p->addModel(modelPENEQUE);
	// p->addModel(modelLIMONADE); //needs rendering optimisations
	p->addModel(modelLIMBO);
	p->addModel(modelPERCO);
	// p->addModel(modelBAFIS);
	p->addModel(modelFFILTR);
	p->addModel(modelBAR);
	p->addModel(modelMINIBAR);
	p->addModel(modelZINC);
	p->addModel(modelFREIN);
	p->addModel(modelHCTIP);
	p->addModel(modelCURT);
	// p->addModel(modelDFUZE); //GPL
	p->addModel(modelREI);
	p->addModel(modelRABBIT);
	p->addModel(modelBISTROT);
	p->addModel(modelSIGMA);
	// p->addModel(modelGARCON); //needs processing and rendering optimisations
	p->addModel(modelVOID);
}
