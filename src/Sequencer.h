//
// Created by nisse on 9/24/22.
//

#ifndef CQUENCER_SEQUENCER_H
#define CQUENCER_SEQUENCER_H


#include "OutputInterface.h"

class Sequencer {
  public:
    int currentStep;
    int maxStep;
    int currentPattern;
    int maxPattern;
    int bpm;
    bool isPlaying;
    OutputInterface outputInterface;

    Sequencer(int maxStepSize, int maxPatternSize) :
        maxStep(maxStepSize), maxPattern(maxPatternSize), outputInterface(8, 12, 11) {

        currentStep = 0;
        currentPattern = 0;
        bpm = 120;

        isPlaying = false;
    }

    void doStep();
};


#endif //CQUENCER_SEQUENCER_H
