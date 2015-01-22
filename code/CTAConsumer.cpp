/***************************************************************************
 CTAConsumer.cpp
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

#include "CTAConsumer.h"
#include <iostream>

namespace CTAAlgorithm {

CTAConsumer::CTAConsumer(CTABuffer* buffer_input) {
	this->buffer_input = buffer_input;
}

void CTAConsumer::setBufferInput(CTABuffer* buffer_input) {
	this->buffer_input = buffer_input;
}

CTABuffer* CTAConsumer::getBufferInput() {
	return buffer_input;
}


//---------

CTABufferCleaner::CTABufferCleaner(CTABuffer* buffer_input) : CTAConsumer(buffer_input) {

}

void *CTABufferCleaner::run() {
	
	std::cout << "Thread cleaner started" << std::endl;
	
	
	while (true) {
		CTAData* d = buffer_input->get();
		//cout << "del" << endl;
		delete d;
	}
	return 0;
	
}

}
