#include "midiPlayer.hpp"

midiPlayer::midiPlayer( uint8_t tonePin_p ){
    score = NULL;
    scorePtr = NULL;
    tonePin = tonePin_p;
    playing = false;
}

void midiPlayer::play( const uint8_t* score_p ){

    if( playing ){
        return;
    }

    score = score_p;
    scorePtr = score;
    playing = true;
}

void midiPlayer::update(){
    uint8_t command;
    uint8_t data;
    // uint8_t channel; // Not used
    uint16_t buffer;
    unsigned long sysTime;

    if( !playing ){
        return;
    }

    sysTime = millis();

    if( nextEvent != 0 ){
        if( sysTime < nextEvent ){
            return;
        }
    }

    command = pgm_read_byte( scorePtr );
    scorePtr++;

    // Check if the command is wait command.
    if( command < 0x80 ){
        data = pgm_read_byte( scorePtr );
        scorePtr++;

        buffer = command << 8;
        buffer |= data;

        nextEvent = sysTime + buffer;

        // Next event can not be 0, to make the delay work;
        if( nextEvent == 0 ){
            nextEvent++;
        }
        return;
    }

    // channel = command & 0x0F; // Parse channel to this. Currently not used.
    command = command & 0xF0;

    switch( command ){
        case MIDI_PLAYNOTE:
            data = pgm_read_byte( scorePtr );
            scorePtr++;
            noTone( tonePin );
            playNote( data );
            break;
        case MIDI_STOPNOTE:
            noTone( tonePin );
            break;
        case MIDI_STOP:
            stop();
            break;
        default:
            break;
    }
}

void midiPlayer::playNote( uint8_t note ){
    float result;
    float a = 440.0; //frequency of A (common value is 440Hz)
    result = (a / 32) * pow(2, ((note - 9) / 12.0));
    if( muted ){
        return;
    }
    tone( tonePin, result );
}

bool midiPlayer::isPlaying(){
    return playing;
}

void midiPlayer::mute( bool state ){
    muted = state;
}


void midiPlayer::stop(){
    playing = false;
    noTone( tonePin );
}