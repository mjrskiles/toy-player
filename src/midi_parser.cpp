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
            midiEvent.data1 = byteStream.nextByte();
            midiEvent.data2 = byteStream.nextByte();
            break;
        case 0x90:
            midiEvent.data1 = byteStream.nextByte();
            midiEvent.data2 = byteStream.nextByte();
            break;
        case 0xA0:
            midiEvent.data1 = byteStream.nextByte();
            midiEvent.data2 = byteStream.nextByte();
            break;
        case 0xB0:
            midiEvent.data1 = byteStream.nextByte();
            midiEvent.data2 = byteStream.nextByte();
            break;
        case 0xE0:
            midiEvent.data1 = byteStream.nextByte();
            midiEvent.data2 = byteStream.nextByte();
            break;
        case 0xC0:
            midiEvent.data1 = byteStream.nextByte();
            break;
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

MidiFileHeader MidiParser::readHeader(ByteStream &byteStream) {
    MidiFileHeader header;
    bool valid = true;

    midi_byte chunkType[4];
    for (int i = 0; i < 4; i++) {
        chunkType[i] = byteStream.nextByte();
    }
    midi_byte headerPattern[4] { 'M','T','h','d'};
    valid = compareByteArrays(headerPattern, chunkType, 4);

    midi_long length = 0;
    length |= byteStream.nextByte() << 24;
    length |= byteStream.nextByte() << 16;
    length |= byteStream.nextByte() << 8;
    length |= byteStream.nextByte();
    valid = (length == 6);

    midi_double_word format = 0;
    format |= byteStream.nextByte() << 8;
    format |= byteStream.nextByte();
    valid = (format < 3);

    midi_double_word numTracks = 0;
    numTracks |= byteStream.nextByte() << 8;
    numTracks |= byteStream.nextByte();

    midi_double_word division = 0;
    division |= byteStream.nextByte() << 8;
    division |= byteStream.nextByte();

    header.chunkType[0] = chunkType[0];
    header.chunkType[1] = chunkType[1];
    header.chunkType[2] = chunkType[2];
    header.chunkType[3] = chunkType[3];

    header.length = length;
    header.format = format;
    header.numTracks = numTracks;
    header.division = division;
    header.isValid = valid;

    return header;
}

bool MidiParser::compareByteArrays(midi_byte *a1, midi_byte *a2, int len) {
    for (int i = 0; i < len; i++) {
        if (a1[i] != a2[i]) return false;
    }
    return true;
}
