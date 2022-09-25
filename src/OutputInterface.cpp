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

void OutputInterface::setLatch(bool state) {
    if (state) {
        digitalWrite(latchPin, LOW);
    } else {
        digitalWrite(latchPin, HIGH);
    }
}

void OutputInterface::shiftOutput(byte data) const {
    shiftOut(dataPin, clockPin, LSBFIRST, data);
}

byte OutputInterface::getByteFromInt(int number){
    return numericArray[number];
}

//void generateOutputData(int bpm, int patternCurrent, int stepCurrent) {
//    String outputString = "";
//
//    char bpmChar = bpm;
//    char patternChar = patternCurrent;
//    char stepChar = stepCurrent;
//
//}l