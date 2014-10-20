#include "RTAConsumer.h"
#include <iostream>

using namespace std;

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


//---------

RTABufferCleaner::RTABufferCleaner(RTABuffer* buffer_input) : RTAConsumer(buffer_input) {

}

void *RTABufferCleaner::run() {
	
	cout << "Thread cleaner started" << endl;
	
	
	while (true) {
		RTAData* d = buffer_input->get();
		//cout << "del" << endl;
		delete d;
	}
	return 0;
	
}