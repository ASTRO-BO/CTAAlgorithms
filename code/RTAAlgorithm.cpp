/***************************************************************************
 RTAAlgorithm.cpp
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

#include "RTAAlgorithm.h"


RTAAlgorithm::RTAAlgorithm::RTAAlgorithm(CTAConfig::CTAMDArray* array, unsigned long buffersize, int nthreads) {
	this->array = array;
	this->buffer = new RTABuffer(buffersize);
	this->nthreads = nthreads;
}


void RTAAlgorithm::RTAAlgorithm::shutdown() {

}

///Put data into local buffer
///\return false it the buffer is full
void RTAAlgorithm::RTAAlgorithm::put(RTAData* data) {
	buffer->put(data);
}

///get processed data from buffer
RTAAlgorithm::RTAData* RTAAlgorithm::RTAAlgorithm::RTAAlgorithm::get() {
	return buffer->get();
}