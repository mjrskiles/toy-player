//
// Created by mjrsk on 12/27/2021.
//

#include "midi_track_stream.h"

TrackEvent MidiTrackEventStream::nextEvent() {
    midi_long vlq = MidiParser::readVariableLengthQuantity(byteStream);
    MidiEvent midiEvent = MidiParser::readMidiEvent(byteStream);
    TrackEvent trackEvent;
    trackEvent.deltaT = vlq;
    trackEvent.midiEvent = midiEvent;
    return trackEvent;
}