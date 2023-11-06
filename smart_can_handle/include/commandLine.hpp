#ifndef __COMMAND_LINE_HPP__
#define __COMMAND_LINE_HPP__

#include "main.hpp"
#include "Commander-API.hpp"
#include "Commander-API-Commands.hpp"
#include "globalResources.hpp"

#define VT100_FMT_REGULAR       "\033[0m"
#define VT100_FMT_BOLD          "\033[1m"

#define VT100_FMT_WHITE     "\033[37m"
#define VT100_FMT_RED       "\033[31m"

#define welcomeText VT100_FMT_WHITE VT100_FMT_BOLD "\r\n"                                                       \
                    "  _                     _    "  VT100_FMT_RED    "  ____   _____ \r\n"     VT100_FMT_WHITE \
                    " | |                   | |   "  VT100_FMT_RED    " / __ \\ / ____|\r\n"    VT100_FMT_WHITE \
                    " | | ____ _ _ __   __ _| |_  "  VT100_FMT_RED    "| |  | | (___  \r\n"     VT100_FMT_WHITE \
                    " | |/ / _` | '_ \\ / _` | __| " VT100_FMT_RED    "| |  | |\\___ \\ \r\n"   VT100_FMT_WHITE \
                    " |   < (_| | |_) | (_| | |_  "  VT100_FMT_RED    "| |__| |____) |\r\n"     VT100_FMT_WHITE \
                    " |_|\\_\\__,_| .__/ \\__,_|\\__|  " VT100_FMT_RED"\\____/|_____/ \r\n"     VT100_FMT_WHITE \
                    "           | |                              \r\n"                                          \
                    "           |_|                              \r\n"                                          \
                    "\r\n" VT100_FMT_REGULAR VT100_FMT_WHITE                                                    \
                    "Created by Daniel Hajnal 2023.\r\n$: "

void commandLineInit();

void commandLineUpdate();

bool logAngle_func( char *args, Stream *response, void* parent );
bool logGyro_func( char *args, Stream *response, void* parent );
bool logTrain_func( char *args, Stream *response, void* parent );
bool beepTest_func( char *args, Stream *response, void* parent );


#endif