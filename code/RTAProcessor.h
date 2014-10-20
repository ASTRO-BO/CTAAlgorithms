/***************************************************************************
 RTAProcessor.h
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

#ifndef _RTAPROCESSOR_H
#define _RTAPROCESSOR_H

#include "CTAMDArray.h"
#include "RTAData.h"
#include "RTABuffer.h"
#include "RTAProducer.h"
#include "RTAConsumer.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include "rtautils/Thread.h"


using namespace std;

namespace RTAAlgorithm {
	

	///RTA algorithm base class
	class RTAProcessor : public RTAConsumer, public RTAProducer {
		
	protected:
		
		CTAConfig::CTAMDArray* array;
		
		
	public:
		
		RTAProcessor(CTAConfig::CTAMDArray* array, RTABuffer* buffer_input = 0, RTABuffer* buffer_output = 0);
		
		virtual void init() = 0;
		
		virtual void processBufferElement();
		
		///write the algorithm in this method. Use this method also the test manually the algorithm
		virtual RTAData* process(RTAData* input) = 0;
		
	};
	
	class RTAProcessorThread : public Thread {
	private:
		
		RTAProcessor* alg;
		
		bool stopb;
		
	public:
				
		void init(RTAProcessor* alg);
		
		void *run();
		
		void stop();
	};
}

#endif