/***************************************************************************
 CTAProcessor.h
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

#ifndef _CTAPROCESSOR_H
#define _CTAPROCESSOR_H

#include <CTAMDArray.h>
#include <rtautils/Thread.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "CTAData.h"
#include "CTABuffer.h"
#include "CTAProducer.h"
#include "CTAConsumer.h"

namespace CTAAlgorithm {
	

	///CTA algorithm base class
	class CTAProcessor : public CTAConsumer, public CTAProducer {
		
	protected:
		
		CTAConfig::CTAMDArray* array;
		
		
	public:
		
		CTAProcessor(CTAConfig::CTAMDArray* array, CTABuffer* buffer_input = 0, CTABuffer* buffer_output = 0);
		
		virtual void init() = 0;
		
		virtual void processBufferElement();
		
		///write the algorithm in this method. Use this method also the test manually the algorithm
		virtual CTAData* process(CTAData* input) = 0;
		
	};
	
	class CTAProcessorThread : public Thread {
	private:
		
		CTAProcessor* alg;
		
		bool stopb;
		
	public:
				
		void init(CTAProcessor* alg);
		
		void *run();
		
		void stop();
	};
}

#endif
