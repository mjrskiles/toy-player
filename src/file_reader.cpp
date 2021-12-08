//
// Created by mjrsk on 12/7/2021.
//

#include "file_reader.h"

uint32_t dumpFileToBuffer(File &file, uint8_t *buffer) {
    int i = 0;
    while (file.available()) {
        uint8_t byte = file.read();
        buffer[i] = byte;
        i++;
    }
    return i;
}
