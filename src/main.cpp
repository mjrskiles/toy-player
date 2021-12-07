#include <Arduino.h>
#include "SD.h"

const char *file_name = "zelda-overworld.mid";
File midi_file;
const int chipSelect = BUILTIN_SDCARD;


void setup() {
// write your initialization code here
    Serial.begin(9600);
    while (!Serial) {;}

    delay(5000);
    Serial.println("Initializing SD card...");
    if (!SD.begin(chipSelect)) {
        Serial.println("initialization failed!");
        return;
    }
    Serial.println("initialization done.");

    // Open the file
    midi_file = SD.open(file_name);
    if (midi_file) {
        Serial.println("file:");

        // read from the file until there's nothing else in it:
        int cols = 0;
        while (midi_file.available()) {
            uint8_t byte = midi_file.read();
            Serial.printf("0x%x ", byte);
            if (cols > 7) {
                Serial.printf("\n");
                cols = 0;
            } else {
                cols++;
            }
        }
        // close the file:
        midi_file.close();
    } else {
        // if the file didn't open, print an error:
        Serial.println("error opening file");
    }
}

void loop() {
// write your code here
}