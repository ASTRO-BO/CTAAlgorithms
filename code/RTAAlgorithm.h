/***************************************************************************
 RTAAlgorithm.h
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

#ifndef _RTAALGORITHM_H
#define _RTAALGORITHM_H

#include "CTAMDArray.h"
#include "RTAData.h"
#include "RTABuffer.h"
#include <stdlib.h>
#include <string>
#include <iostream>


using namespace std;

namespace RTAAlgorithm {

	class RTAAlgorithm {
		
	private:
		
		CTAConfig::CTAMDArray* array;
		
		RTABuffer* buffer;
		
		int nthreads;
		
	public:
		
		RTAAlgorithm(CTAConfig::CTAMDArray* array, unsigned long buffersize, int nthreads);
		
		virtual void init() = 0;
		
		///write the algorithm in this method
		virtual RTAData* process(RTAData* input) = 0;
		
		virtual void shutdown();
		
		///Put data into local buffer
		///\return false it the buffer is full
		void put(RTAData* data);
		
		///get processed data from buffer
		RTAData* get();
	};
	
}

#endif