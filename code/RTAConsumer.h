/***************************************************************************
 RTAConsumer.h
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

#ifndef _RTACONSUMER_H
#define _RTACONSUMER_H

#include "RTABuffer.h"
#include "rtautils/Thread.h"

using namespace std;

namespace RTAAlgorithm {
	
	
	///RTA algorithm base class
	class RTAConsumer {
		
	protected:
		
		RTABuffer* buffer_input;
		
	public:
		
		RTAConsumer(RTABuffer* buffer_input);
		
		void setBufferInput(RTABuffer* buffer_input);
		
		RTABuffer* getBufferInput();
		
	};
	
	
	class RTABufferCleaner : public RTAConsumer, public Thread {
	
	public:
		
		RTABufferCleaner(RTABuffer* buffer_input);
		
		void *run();
	};
	
}

#endif