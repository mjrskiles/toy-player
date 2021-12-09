//
// Created by mjrsk on 12/8/2021.
//

#include "midi_parser.h"

midi_long MidiParser::readVariableLengthQuantity(ByteStream &byteStream) {
    uint8_t buf[4]; // max size of a VLQ is going to be 4 bytes
    int numRead = 0;
    uint8_t lastRead = 0;
    do {
        lastRead = byteStream.nextByte();
        buf[numRead] = lastRead & 127;
//        Serial.printf("VLQ: read byte %x\n", lastRead);
        numRead++;
    } while (lastRead & (uint8_t)128);
    uint32_t vlq = 0;
    for (int i = 0; i < numRead; i++) {
        vlq |= buf[i] << ((numRead - i - 1) * 7);
    }
//    Serial.printf("Assembled VLQ value %d\n", vlq);
    return vlq;
}

MidiEvent MidiParser::readMidiEvent(ByteStream &byteStream) {
    MidiEvent midiEvent;
    midi_byte status = byteStream.nextByte();
    switch (status & 0xF0) {
        case 0x80: // Note Off
        case 0x90:
        case 0xA0:
        case 0xB0:
        case 0xE0:
            midiEvent.data1 = byteStream.nextByte();
            midiEvent.data2 = byteStream.nextByte();
            break;
        case 0xC0:
        case 0xD0:
            midiEvent.data1 = byteStream.nextByte();
            break;
        default:
            midiEvent.data1 = byteStream.nextByte();
            midiEvent.data2 = byteStream.nextByte();
            break;
    }
    midiEvent.statusWord = status;
    return midiEvent;
}
