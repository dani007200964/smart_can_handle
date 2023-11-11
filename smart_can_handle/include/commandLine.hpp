#ifndef __COMMAND_LINE_HPP__
#define __COMMAND_LINE_HPP__

#include "main.hpp"
#include "Commander-API.hpp"
#include "Commander-API-Commands.hpp"
#include "Commander-Arguments.hpp"
#include "globalResources.hpp"

#define VT100_FMT_REGULAR       "\033[0m"
#define VT100_FMT_BOLD          "\033[1m"

#define VT100_FMT_WHITE     "\033[37m"
#define VT100_FMT_RED       "\033[31m"

#define welcomeText VT100_FMT_WHITE VT100_FMT_REGULAR "\r\n"                                                       \
                    "  _                     _    "      "  ____   _____ \r\n"      \
                    " | |                   | |   "      " / __ \\ / ____|\r\n"     \
                    " | | ____ _ _ __   __ _| |_  "      "| |  | | (___  \r\n"      \
                    " | |/ / _` | '_ \\ / _` | __| "     "| |  | |\\___ \\ \r\n"    \
                    " |   < (_| | |_) | (_| | |_  "      "| |__| |____) |\r\n"      \
                    " |_|\\_\\__,_| .__/ \\__,_|\\__|  " "\\____/|_____/ \r\n"      \
                    "           | |                              \r\n"                                          \
                    "           |_|                              \r\n"                                          \
                    "\r\n"                                                      \
                    "Daniel Hajnal 2023.\r\n$: "

void commandLineInit();

void commandLineUpdate();

bool logAngle_func( char *args, Stream *response, void* parent );
bool logGyro_func( char *args, Stream *response, void* parent );
bool logTrain_func( char *args, Stream *response, void* parent );
bool trainEn_func( char *args, Stream *response, void* parent );
bool trainDis_func( char *args, Stream *response, void* parent );
bool logTrigger_func( char *args, Stream *response, void* parent );
bool play_func( char *args, Stream *response, void* parent );
bool stop_func( char *args, Stream *response, void* parent );
bool logToast_func( char *args, Stream *response, void* parent );
bool mute_func( char *args, Stream *response, void* parent );
bool unmute_func( char *args, Stream *response, void* parent );


#endif