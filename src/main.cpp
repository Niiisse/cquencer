#include <Arduino.h>
#include "Sequencer.h"
#include "OutputInterface.h"

Sequencer sequencer(15, 8);

void setup() {
    Serial.begin(115200);
    Serial.println("Initialized");
}

void loop() {
    sequencer.doStep();
}
