/***************************************************************************
 RTAProducer.h
 -------------------
 copyright            : (C) 2014 Andrea Bulgarelli
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

#ifndef _RTAPRODUCER_H
#define _RTAPRODUCER_H

#include "RTABuffer.h"


using namespace std;

namespace RTAAlgorithm {
	
	
	///RTA algorithm base class
	class RTAProducer {
		
	protected:
		
		RTABuffer* buffer_output;
		
	public:
		
		RTAProducer(RTABuffer* buffer_output);
		
		void setBufferOutput(RTABuffer* buffer_output);
		
		RTABuffer* getBufferOutput();
		
	};
	
}

#endif
