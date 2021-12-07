//
// Created by Michael Skiles on 12/7/21.
//

#ifndef MIDI_PLAYER_MIDI_TYPES_H
#define MIDI_PLAYER_MIDI_TYPES_H

#include "cstdint"

typedef uint8_t midi_byte;
typedef uint32_t midi_long;
typedef struct MidiEvent {
    midi_byte statusWord = 0;
    midi_byte data1 = 0;
    midi_byte data2 = 0;
} MidiEvent;
typedef struct TrackEvent {
    midi_long deltaT;
    MidiEvent midiEvent;
} TrackEvent;

#endif //MIDI_PLAYER_MIDI_TYPES_H
