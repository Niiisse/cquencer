//
// Created by nisse on 9/24/22.
//

#include "Sequencer.h"

void Sequencer::doStep() {
    if (currentStep < maxStep) {
        currentStep++;
    } else {
        currentStep = 0;
    }

    outputInterface.outputData(outputInterface.numericArray[currentStep]);
    delay(500);
}