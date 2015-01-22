/***************************************************************************
 CTAProducer.cpp
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

#include "CTAProducer.h"

namespace CTAAlgorithm {

CTAProducer::CTAProducer(CTABuffer* buffer_output) {
	this->buffer_output = buffer_output;
}

void CTAProducer::setBufferOutput(CTABuffer* buffer_output) {
	this->buffer_output = buffer_output;
}

CTABuffer* CTAProducer::getBufferOutput() {
	return this->buffer_output;
}

}
