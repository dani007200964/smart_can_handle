#ifndef __GLOBAL_RESOURCES_HPP__
#define __GLOBAL_RESOURCES_HPP__

#include "main.hpp"
#include "MPU6050.h"
#include "Commander-API.hpp"

extern logType_t logType;

// MPU6050 Sesnor Object.
extern MPU6050 motionSensor;

// We have to create an object from Commander class.
extern Commander commander;



#endif