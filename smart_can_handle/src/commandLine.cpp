#include "commandLine.hpp"

Commander::systemCommand_t API_tree[] = {
    SYSTEM_COMMAND_I2CSCAN,
    //SYSTEM_COMMAND_DIGITALREAD,
    //SYSTEM_COMMAND_DIGITALWRITE,
    //SYSTEM_COMMAND_PINMODE,


    systemCommand( "trainEn", "", trainEn_func ),
    systemCommand( "trainDis", "", trainDis_func ),
    systemCommand( "logAngle", "", logAngle_func ),
    systemCommand( "logGyro", "", logGyro_func ),
    systemCommand( "logTrain", "", logTrain_func ),
    systemCommand( "logTrigger", "", logTrigger_func ),
    systemCommand( "beepTest", "", beepTest_func ),
    systemCommand( "play", "", play_func ),
    systemCommand( "stop", "", stop_func ),
    systemCommand( "logToast", "", logToast_func ),
    systemCommand( "mute", "", mute_func ),
    systemCommand( "unmute", "", unmute_func )
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

bool trainEn_func( char *args, Stream *response, void* parent ){
    pinMode( 11, OUTPUT );
    digitalWrite( 11, LOW );
    pinMode( TRAIN_BUTTON_PIN, INPUT );
    digitalWrite( TRAIN_BUTTON_PIN, HIGH );
    return true;
}

bool trainDis_func( char *args, Stream *response, void* parent ){
    pinMode( 11, INPUT );
    pinMode( TRAIN_BUTTON_PIN, INPUT );
    digitalWrite( TRAIN_BUTTON_PIN, LOW );
    return true;
}

bool logTrigger_func( char *args, Stream *response, void* parent ){
  logType = LOG_TRIGGER;
  return true;
}

bool logToast_func( char *args, Stream *response, void* parent ){
  logType = LOG_TOAST;
  return true;
}

bool play_func( char *args, Stream *response, void* parent ){
    Argument musicID( args, 0 );

    musicID.parseInt();

    if( !musicID ){
        Serial.println( F( "---- Available songs ----" ) );
        Serial.println( F( " -Barbie       : 1" ) );
        Serial.println( F( " -Drink        : 2" ) );
        Serial.println( F( " -Movin Cruisin: 3" ) );
        Serial.println( F( " -Lalalala     : 4" ) );
        Serial.println( F( " -Rick         : 5" ) );
        Serial.println( F( " -We're Not    : 6" ) );
        Serial.println( F( " -Vodka        : 7" ) );
        Serial.println( F( " -Deja Vu      : 8" ) );
        Serial.println( F( " -Titanic      : 9" ) );
        return true;
    }

    if( player.isPlaying() ){
        Serial.print( F( "Song is already playing." ) );
        return true;
    }

    switch( (int)musicID ){
        case 1:
            player.play( barbieMidi );
            break;
        case 2:
            player.play( drinkMidi );
            break;
        case 3:
            player.play( movinCruisinMidi );
            break;
        case 4:
            player.play( lalaMidi );
            break;
        case 5:
            player.play( rickMidi );
            break;
        case 6:
            player.play( weReNotGonnaMidi );
            break;
        case 7:
            player.play( vodkaMidi );
            break;
        case 8:
            player.play( dejaVuMidi );
            break;
        case 9:
            player.play( titanicMidi );
            break;
        default:
            Serial.print( F( "Selected ID not valid!" ) );
            break;
    }

    return true;
}

bool stop_func( char *args, Stream *response, void* parent ){
    player.stop();
    return true;
}

bool mute_func( char *args, Stream *response, void* parent ){
    buzzerPin = 10;
    player.mute( true );
    noTone( BUZZER_PIN );
    return true;
}

bool unmute_func( char *args, Stream *response, void* parent ){
    buzzerPin = BUZZER_PIN;
    player.mute( false );
    return true;
}

