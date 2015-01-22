/***************************************************************************
 CTAProcessor.cpp
 -------------------
 copyright            : (C) 2014 Andrea Bulgarelli, Alessio Aboudan
 email                : bulgarelli@iasfbo.inaf.it
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software for non commercial purpose              *
 *   and for public research institutes; you can redistribute it and/or    *
 *   modify it under the terms of the GNU General Public License.          *
 *   For commercial purpose see appropriate license terms                  *
 *                                                                         *
 ***************************************************************************/

#include "CTAProcessor.h"

namespace CTAAlgorithm {

void CTAProcessorThread::init(CTAProcessor* alg) {
	this->alg = alg;
	this->stopb = false;
}

void *CTAProcessorThread::run() {
	while(!stopb) {
		alg->processBufferElement();
	}
	return 0;
}

void CTAProcessorThread::stop() {
	stopb = true;
}


CTAProcessor::CTAProcessor(CTAConfig::CTAMDArray* array, CTABuffer* buffer_input, CTABuffer* buffer_output) : CTAConsumer(buffer_input), CTAProducer(buffer_output) {
	this->array = array;
}

void CTAProcessor::processBufferElement() {
	CTAData* input = buffer_input->get();
	CTAData* output = process(input);
	if(buffer_output)
		buffer_output->put(output);
}

}
