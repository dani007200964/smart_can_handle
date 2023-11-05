#ifndef __COMMAND_LINE_HPP__
#define __COMMAND_LINE_HPP__

#include "main.hpp"
#include "Commander-API.hpp"
#include "Commander-API-Commands.hpp"

void commandLineInit();

void commandLineUpdate();

bool logAngle_func( char *args, Stream *response, void* parent );
bool logGyro_func( char *args, Stream *response, void* parent );
bool logTrain_func( char *args, Stream *response, void* parent );


#endif