/***************************************************************************
 CTAConsumer.h
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

#ifndef _CTACONSUMER_H
#define _CTACONSUMER_H

#include "CTABuffer.h"
#include <ctautils/Thread.h>

namespace CTAAlgorithm {
	
	
	///CTA algorithm base class
	class CTAConsumer {
		
	protected:
		
		CTABuffer* buffer_input;
		
	public:
		
		CTAConsumer(CTABuffer* buffer_input);
		
		void setBufferInput(CTABuffer* buffer_input);
		
		CTABuffer* getBufferInput();
		
	};
	
	
	class CTABufferCleaner : public CTAConsumer, public CTAUtils::Thread {
	
	public:
		
		CTABufferCleaner(CTABuffer* buffer_input);
		
		void *run();
	};
	
}

#endif
