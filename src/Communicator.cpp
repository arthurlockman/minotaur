#include "Communicator.h"

Communicator::Communicator(ISensorManager* sensorManager) {
    this->sensorManager = sensorManager;
    this->outBuffer = new std::queue<Message*>;
}

bool Communicator::attachArduino (string comPort) {

}

void Communicator::sendNextMsg() {
    // @TODO: We need to check for .empty() before we ever try
    // to access .front or .pop
    std::cout << this->outBuffer->front()->write() << endl;
    this->outBuffer->pop(); 
}

void Communicator::readData() {

}

void queueMsg(Message* msg) {
    this->outBuffer->push(msg);
}
