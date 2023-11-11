#ifndef __GLOBAL_RESOURCES_HPP__
#define __GLOBAL_RESOURCES_HPP__

#include "main.hpp"
#include "MPU6050.h"
#include "Commander-API.hpp"
#include "midiPlayer.hpp"

extern logType_t logType;

// MPU6050 Sesnor Object.
extern MPU6050 motionSensor;

// We have to create an object from Commander class.
extern Commander commander;

extern midiPlayer player;

extern const uint8_t* barbieMidi;
extern const uint8_t* lalaMidi;
extern const uint8_t* movinCruisinMidi;
extern const uint8_t* drinkMidi;
extern const uint8_t* rickMidi;
extern const uint8_t* weReNotGonnaMidi;
extern const uint8_t* vodkaMidi;
extern const uint8_t* dejaVuMidi;
extern const uint8_t* titanicMidi;
extern const uint8_t* mariaMidi;
extern const uint8_t* nyanMidi;
extern const uint8_t* shrekMidi;
extern const uint8_t* guntherMidi;
extern const uint8_t* ripMidi;
extern const uint8_t* xpMidi;

extern const uint8_t* trackList[];

extern uint8_t trackListSize;
extern uint8_t songID;

extern int beepPeriod;
extern int beepFrequency;

extern int buzzerPin;



#endif