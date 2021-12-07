//
// Created by Michael Skiles on 12/7/21.
//

#ifndef MIDI_PLAYER_BYTE_STREAM_H
#define MIDI_PLAYER_BYTE_STREAM_H

#include "cstdint"

class ByteStream {
public:
    ByteStream(uint8_t *buffer, int size) : _buffer(buffer), _size(size) {}

    bool hasNext() { return _offset < _size; }
    uint8_t nextByte() { return _buffer[_offset++]; }
    int size() { return _size; }
    void reset() { _offset = 0; }
protected:
    uint8_t *_buffer;
    int _size;
    int _offset = 0;
};

#endif //MIDI_PLAYER_BYTE_STREAM_H
