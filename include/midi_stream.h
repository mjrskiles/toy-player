//
// Created by Michael Skiles on 12/7/21.
//

#ifndef MIDI_PLAYER_MIDI_STREAM_H
#define MIDI_PLAYER_MIDI_STREAM_H

#include "midi_types.h"

class MidiStream {
public:
    bool hasNext();
    TrackEvent nextEvent();
protected:
};

#endif //MIDI_PLAYER_MIDI_STREAM_H
