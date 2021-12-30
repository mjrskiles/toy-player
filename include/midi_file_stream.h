//
// Created by Michael Skiles on 12/7/21.
//

#ifndef MIDI_PLAYER_MIDI_STREAM_H
#define MIDI_PLAYER_MIDI_STREAM_H

#include "midi_types.h"
#include "midi_track_stream.h"

#define MAX_TRACKS 16

typedef struct MidiTrackChunk {
    midi_byte chunkType[4]; // Should always == "MTrk"
    midi_long length;
    MidiTrackEventStream &trackStream;
};
/*
 * This class represents the midi file as an object
 * It has data from the header and references to the individual track streams
 */
class MidiFileStream {
public:
    /*
     * The constructor reads in the header and strings up the tracks
     */
    explicit MidiFileStream(ByteStream &byteStream);
protected:
    ByteStream &byteStream;
    MidiFileHeader header;
    MidiTrackChunk *trackChunks;
};

#endif //MIDI_PLAYER_MIDI_STREAM_H
