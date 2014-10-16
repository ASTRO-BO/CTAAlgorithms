/***************************************************************************
 RTABuffer.h
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

#ifndef _RTABUFFER_H
#define _RTABUFFER_H


#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include "RTAData.h"


namespace RTAAlgorithm {
	
	class RTABuffer {
		
	private:
		
		RTAAlgorithm::RTAData** buffer;
		int fill;
		int use;
		sem_t empty;
		sem_t full;
		sem_t mutex;
		
		unsigned long size;
		
	public:
		
		RTABuffer(unsigned long size);
		
		///Put data into local buffer
		///\return false it the buffer is full
		void put(RTAData* data);
		
		///get processed data from buffer
		RTAData* get();
		
		unsigned long getBufferSize();
		
		
	};
}

#endif