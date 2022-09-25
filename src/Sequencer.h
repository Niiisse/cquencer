//
// Created by nisse on 9/24/22.
//

#ifndef CQUENCER_SEQUENCER_H
#define CQUENCER_SEQUENCER_H

#include "OutputInterface.h"

class Sequencer {
public:
    OutputInterface outputInterface;

    int stepCurrent;
    int stepMax;
    int patternCurrent;
    int patternMax;
    int bpm;
    bool patternLoop;
    bool isPlaying;
    byte outputArray[3] {};

    Sequencer(int maxStepSize, int maxPatternSize) :
            outputInterface(8, 12, 11), stepMax(maxStepSize), patternMax(maxPatternSize) {

        stepCurrent = 0;
        patternCurrent = 0;
        bpm = 9;

        isPlaying = false;
        patternLoop = false;
    }

    void doStep();
    void clampStep();
    static int clampValue(int val, int min, int max);
    void compileOutput(int bpm, int pattern, int step);
    void sendOutput();
};


#endif //CQUENCER_SEQUENCER_H
