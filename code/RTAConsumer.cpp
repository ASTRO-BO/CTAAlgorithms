#include "RTAConsumer.h"

using namespace RTAAlgorithm;

RTAConsumer::RTAConsumer(RTABuffer* buffer_input) {
	this->buffer_input = buffer_input;
}

void RTAConsumer::setBufferInput(RTABuffer* buffer_input) {
	this->buffer_input = buffer_input;
}

RTABuffer* RTAConsumer::getBufferInput() {
	return buffer_input;
}