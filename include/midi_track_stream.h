//
// Created by mjrsk on 12/27/2021.
//

#ifndef TOY_PLAYER_MIDI_TRACK_STREAM_H
#define TOY_PLAYER_MIDI_TRACK_STREAM_H

#include "midi_types.h"
#include "byte_stream.h"
#include "midi_parser.h"

class MidiTrackEventStream {
public:
    bool hasNext() { return byteStream.hasNext(); }
    TrackEvent nextEvent();
protected:
    bool finished = false;
    ByteStream &byteStream;
};

#endif //TOY_PLAYER_MIDI_TRACK_STREAM_H
