#include "commandLine.hpp"

Commander::systemCommand_t API_tree[] = {
    SYSTEM_COMMAND_I2CSCAN,
    SYSTEM_COMMAND_DIGITALREAD,
    systemCommand( "logAngle", "", logAngle_func ),
    systemCommand( "logGyro", "", logGyro_func ),
    systemCommand( "logTrain", "", logTrain_func ),
    systemCommand( "beepTest", "", beepTest_func )
};

char commandBuffer[ COMMAND_SIZE ];

// We have to create an object from Commander class.
Commander commander;

void commandLineInit(){

    // There is an option to attach a debug channel to Commander.
    // It can be handy to find any problems during the initialization
    // phase. In this example, we will use Serial for this.
    commander.attachDebugChannel( &Serial );

    // At start, Commander does not know anything about our commands.
    // We have to attach the API_tree array from the previous steps
    // to Commander to work properly.
    commander.attachTree( API_tree );

    // After we attached the API_tree, Commander has to initialize
    // itself for the fastest runtime possible. It creates a balanced
    // binary tree from the API_tree to boost the search speed.
    // This part uses some recursion, to make the code space small.
    // But recursion is a bit stack hungry, so please initialize
    // Commander at the beginning of your code to prevent stack-overlow.
    commander.init();

}

void commandLineUpdate(){
    if( logType == NO_LOG ){
        commander.update( commandBuffer, COMMAND_SIZE, &Serial );
    }
}

bool logAngle_func( char *args, Stream *response, void* parent ){
  if( response ){
    response -> println( F( "Angle data:" ) );
  }
  logType = LOG_ANGLE;
  return true;
}

bool logGyro_func( char *args, Stream *response, void* parent ){
  if( response ){
    response -> println( F( "Gyro data:" ) );
  }
  logType = LOG_GYRO;
  return true;
}

bool logTrain_func( char *args, Stream *response, void* parent ){
  if( response ){
    response -> println( F( "Train data:" ) );
  }
  logType = LOG_TRAIN;
  return true;
}

bool beepTest_func( char *args, Stream *response, void* parent ){
    tone( BUZZER_PIN, 440, 500 );
    return true;
}