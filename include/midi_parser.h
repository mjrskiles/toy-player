//
// Created by mjrsk on 12/8/2021.
//

#ifndef TOY_PLAYER_MIDI_PARSER_H
#define TOY_PLAYER_MIDI_PARSER_H

#include "midi_types.h"
#include "byte_stream.h"

class MidiParser {
public:
    static midi_long readVariableLengthQuantity(ByteStream &byteStream);
    static MidiEvent readMidiEvent(ByteStream &byteStream);
    static MidiFileHeader readHeader(ByteStream &byteStream);
private:
    static bool compareByteArrays(midi_byte *a1, midi_byte *a2, int len);
};

#endif //TOY_PLAYER_MIDI_PARSER_H
