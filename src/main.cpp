#include <Arduino.h>
#include "Sequencer.h"
#include "OutputInterface.h"

Sequencer sequencer(15, 8);
//OutputInterface outputInterface(8, 12, 11);

void setup() {
    Serial.begin(115200);
}

void loop() {
    for (int i = 0; i < 16; i++) {
        outputInterface.outputData(outputInterface.numericArray[i]);

        Serial.println(i);
        delay(1000);

    }
}
