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

extern int beepPeriodOff;
extern int beepFrequency;

extern int buzzerPin;



#endif