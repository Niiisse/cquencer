//
// Created by nisse on 9/24/22.
//

#ifndef CQUENCER_SEQUENCER_H
#define CQUENCER_SEQUENCER_H


class Sequencer {
  public:
    int currentStep;
    int maxStep;
    int currentPattern;
    int maxPattern;
    int bpm;
    bool isPlaying;

    Sequencer(int maxStepSize, int maxPatternSize) :
        maxStep(maxStepSize), maxPattern(maxPatternSize) {

        currentStep = 0;
        currentPattern = 0;
        bpm = 120;

        isPlaying = false;
    }

    void doStep();
};


#endif //CQUENCER_SEQUENCER_H
