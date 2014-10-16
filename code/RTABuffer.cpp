/***************************************************************************
 RTABuffer.cpp
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

#include "RTABuffer.h"

RTAAlgorithm::RTABuffer::RTABuffer(unsigned long size) {
	this->buffer = (RTAData**) new RTAData* [size];
	this->size = size;
	fill = 0;
	use  = 0;
	
	sem_init(&empty, 0, size); // MAX buffers are empty to begin with...
	sem_init(&full, 0, 0);    // ... and 0 are full
	sem_init(&mutex, 0, 1);    // mutex = 1 since it a lock
}

void RTAAlgorithm::RTABuffer::put(RTAAlgorithm::RTAData* data) {
	sem_wait(&empty);
 
	// scope of lock reduced
	sem_wait(&mutex);
	
	this->buffer[fill] = data;
	fill = (fill + 1) % size;
	
	sem_post(&mutex);
	
	sem_post(&full);
}

bool RTAAlgorithm::RTABuffer::isFull() {
	if(fill == size -1)
		return true;

	return false;
}

RTAAlgorithm::RTAData* RTAAlgorithm::RTABuffer::get() {
	sem_wait(&full);
	
	// scope of lock reduced
	sem_wait(&mutex);
	
	RTAAlgorithm::RTAData* b = buffer[use];
	use = (use + 1) % size;
	
	sem_post(&mutex);
	
	sem_post(&empty);
	
	return b;
}

unsigned long RTAAlgorithm::RTABuffer::getBufferSize() {
	return this->size;
}