//
// Created by Michael Skiles on 12/7/21.
//

#ifndef MIDI_PLAYER_MIDI_PLAYER_H
#define MIDI_PLAYER_MIDI_PLAYER_H

#include "cstdint"
#include "midi_file_stream.h"
/*
 * The main coordinator. Takes a file in and sends midi messages out
 *
 * main components:
 *   file/song stream
 *   midi parser
 *   midi controller
 */

#define NUM_MIDI_TRACKS 16

class MidiPlayer {
public:
    MidiPlayer(uint8_t *fileBuffer);

    // Should leave the player in a ready to play state (read the header, put pointers to each track)
    void init(uint32_t bufferSize);
    void play();
    void pause();
    void reset();

protected:
    MidiFileStream midiFileStream;
};

#endif //MIDI_PLAYER_MIDI_PLAYER_H
