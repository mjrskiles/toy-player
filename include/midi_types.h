//
// Created by Michael Skiles on 12/7/21.
//

#ifndef MIDI_PLAYER_MIDI_TYPES_H
#define MIDI_PLAYER_MIDI_TYPES_H

#include "cstdint"

typedef uint8_t midi_byte;
typedef uint16_t midi_double_word;
typedef uint32_t midi_long;
typedef struct MidiEvent {
    midi_byte statusWord = 0;
    midi_byte data1;
    midi_byte data2;
} MidiEvent;
typedef struct TrackEvent {
    midi_long deltaT;
    MidiEvent midiEvent;
} TrackEvent;

typedef struct MidiFileHeader {
    midi_byte chunkType[4]; // Should always == "MThd"
    midi_long length; // Should always == 6
    midi_double_word format;
    midi_double_word numTracks;
    midi_double_word division;
    bool isValid = false;
} MidiFileHeader;



#endif //MIDI_PLAYER_MIDI_TYPES_H
