//
// Created by Michael Skiles on 12/7/21.
//

#ifndef MIDI_PLAYER_MIDI_PLAYER_H
#define MIDI_PLAYER_MIDI_PLAYER_H

#include "cstdint"
/*
 * The main coordinator. Takes a file in and sends midi messages out
 *
 * main components:
 *   file/song stream
 *   midi parser
 *   midi controller
 */

class MidiPlayer {
public:
protected:
    uint8_t *_fileBuffer;
    uint32_t _bufferSize;

};

#endif //MIDI_PLAYER_MIDI_PLAYER_H
