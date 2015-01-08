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
#include <string>

using namespace std;

//the producer/consumer (aka Bounded Buffer) problem.
namespace RTAAlgorithm {
	
	class RTABuffer {
		
	private:
		
		RTAAlgorithm::RTAData** buffer;
		int fill;
		int use;
		int circularBuffer;
		sem_t* empty;
		sem_t* full;
		pthread_mutex_t mutex;
		string semname1;
		string semname2;

		string _name;
		
		int size;
		
	public:
		
		RTABuffer(string name, int size);
		~RTABuffer();
		///Put data into local buffer
		///The call is blocking if the buffer is full. Test it before with isFull()
		void put(RTAData* data);
		
		///get processed data from buffer
		///The call is blocking if the buffer is empty.
		RTAData* get();

		string getName() {
			return _name;
		}
		
		int getBufferSize();
		
		bool isFull();
		
		RTAData* getNextCircularBuffer();
	};
}

#endif