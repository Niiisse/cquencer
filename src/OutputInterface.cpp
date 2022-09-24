//
// Created by nisse on 9/24/22.
//

#include "OutputInterface.h"

OutputInterface::OutputInterface(int latch, int clock, int data) :
        latchPin(latch), clockPin(clock), dataPin(data) {

    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);

}

void OutputInterface::outputData(byte data) const {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, data);
    digitalWrite(latchPin, HIGH);
}

