//
// Created by nisse on 9/24/22.
//

#include "Sequencer.h"

void Sequencer::doStep() {
    clampStep();

    compileOutput(bpm, patternCurrent, stepCurrent);
    sendOutput();

    bpm++;

    delay(500);
}

void Sequencer::clampStep() {
    if (stepCurrent < stepMax) {
        stepCurrent++;
    } else {
        stepCurrent = 0;
        if (!patternLoop) {
            patternCurrent = clampValue(patternCurrent, 0, patternMax);
        }
    }
}

void Sequencer::sendOutput() {
    outputInterface.setLatch(true);

    for (unsigned char i : outputArray) {
        outputInterface.shiftOutput(outputInterface.getByteFromInt(i));
    }

    outputInterface.setLatch(false);
}

int Sequencer::clampValue(int val, int min, int max) {
    if (val < max) {
        val++;
    } else {
        val = min;
    }

    return val;
}

void Sequencer::compileOutput(int bpm, int pattern, int step) {
    int iArr[3] = {0,0,0};
    int i = 0;

    while(bpm > 9) {
        int mod = bpm % 10;
        iArr[i] = mod;

        bpm /= 10;
        i++;
    }

    iArr[i] = bpm;

    for (int j = 0; j < 3; ++j) {
        outputArray[j] = iArr[j];
    }
}