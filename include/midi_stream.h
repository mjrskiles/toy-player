//
// Created by Michael Skiles on 12/7/21.
//

#ifndef MIDI_PLAYER_MIDI_STREAM_H
#define MIDI_PLAYER_MIDI_STREAM_H

#include "midi_types.h"
#include "byte_stream.h"
#include "midi_parser.h"

class MidiTrackStream {
public:
    bool hasNext() { return byteStream.hasNext(); }
    TrackEvent nextEvent();
protected:
    bool finished = false;
    ByteStream &byteStream;
};

#endif //MIDI_PLAYER_MIDI_STREAM_H
