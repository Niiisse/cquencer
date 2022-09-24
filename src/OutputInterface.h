//
// Created by nisse on 9/24/22.
//

#ifndef CQUENCER_OUTPUTINTERFACE_H
#define CQUENCER_OUTPUTINTERFACE_H

#include <Arduino.h>

class OutputInterface {
  public:
    const int latchPin;
    const int clockPin;
    const int dataPin;
    const byte numericArray[16]{
            0b10000001,  // 0
            0b11101101,  // 1
            0b01000011,  // 2
            0b01001001,  // 3
            0b00101101,  // 4
            0b00011001,  // 5
            0b00010001,  // 6
            0b11001101,  // 7
            0b00000001,  // 8
            0b00001001,  // 9
            0b00000101, // A
            0b00110001, // B
            0b01110011, // C
            0b01100001, // D
            0b00010011, // E
            0b00010111  // F
    };

    OutputInterface(int latch, int clock, int data);

    void outputData(byte data) const;
};

#endif //CQUENCER_OUTPUTINTERFACE_H
