#include "RTAProducer.h"

using namespace RTAAlgorithm;

RTAProducer::RTAProducer(RTABuffer* buffer_output) {
	this->buffer_output = buffer_output;
}

void RTAProducer::setBufferOutput(RTABuffer* buffer_output) {
	this->buffer_output = buffer_output;
}

RTABuffer* RTAProducer::getBufferOutput() {
	return this->buffer_output;
}