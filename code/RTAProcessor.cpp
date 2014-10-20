/***************************************************************************
 RTAProcessor.cpp
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

#include "RTAProcessor.h"

using namespace RTAAlgorithm;

void RTAProcessorThread::init(RTAProcessor* alg) {
	this->alg = alg;
	this->stopb = false;
}

void *RTAProcessorThread::run() {
	while(!stopb) {
		alg->processBufferElement();
	}
	return 0;
}

void RTAProcessorThread::stop() {
	stopb = true;
}


RTAProcessor::RTAProcessor(CTAConfig::CTAMDArray* array, RTABuffer* buffer_input, RTABuffer* buffer_output) : RTAConsumer(buffer_input), RTAProducer(buffer_output) {
	this->array = array;
}

void RTAProcessor::processBufferElement() {
	RTAData* input = buffer_input->get();
	RTAData* output = process(input);
	if(buffer_output)
		buffer_output->put(output);
}


