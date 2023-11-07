#ifndef __SENSOR_HPP__
#define __SENSOR_HPP__

#include "globalResources.hpp"
#include "MPU6050.h"
#include "Wire.h"
#include "Commander-API-Commands.hpp"

void sensorInit();

void sensorUpdate();

void printTrainData();

#endif