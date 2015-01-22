/***************************************************************************
 CTAProducer.h
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

#ifndef _CTAPRODUCER_H
#define _CTAPRODUCER_H

#include "CTABuffer.h"

namespace CTAAlgorithm {
	
	
	///CTA algorithm base class
	class CTAProducer {
		
	protected:
		
		CTABuffer* buffer_output;
		
	public:
		
		CTAProducer(CTABuffer* buffer_output);
		
		void setBufferOutput(CTABuffer* buffer_output);
		
		CTABuffer* getBufferOutput();
		
	};
	
}

#endif
