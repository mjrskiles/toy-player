//
// Created by Michael Skiles on 12/7/21.
//

#include "midi_stream.h"

TrackEvent MidiTrackStream::nextEvent() {
    midi_long vlq = MidiParser::readVariableLengthQuantity(byteStream);
    MidiEvent midiEvent = MidiParser::readMidiEvent(byteStream);
    TrackEvent trackEvent;
    trackEvent.deltaT = vlq;
    trackEvent.midiEvent = midiEvent;
    return trackEvent;
}
