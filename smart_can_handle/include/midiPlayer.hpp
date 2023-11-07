#ifndef __MIDI_PLAYER_HPP__
#define __MIDI_PLAYER_HPP__

#include <stdint.h>
#include <Arduino.h>

// Simple parser to this beauty:
// https://github.com/LenShustek/miditones

#define MIDI_PLAYNOTE	0x90
#define MIDI_STOPNOTE	0x80
#define MIDI_INSTRUMENT 0xc0
#define MIDI_RESTART	0xe0
#define MIDI_STOP   	0xf0

class midiPlayer{

public:

    midiPlayer( uint8_t tonePin_p );

    void play( const uint8_t* score_p );

    void update();

    void playNote( uint8_t note );

    bool isPlaying();

    void stop();

private:
    const uint8_t* score = NULL;
    const uint8_t* scorePtr = NULL;
    unsigned long nextEvent = 0;
    uint8_t tonePin = 0;
    bool playing = false;
};

#endif