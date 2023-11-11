#include "commandLine.hpp"

Commander::systemCommand_t API_tree[] = {
    SYSTEM_COMMAND_I2CSCAN,
    SYSTEM_COMMAND_REBOOT,
    systemCommand( "trainEn", "", trainEn_func ),
    systemCommand( "trainDis", "", trainDis_func ),
    systemCommand( "logAngle", "", logAngle_func ),
    systemCommand( "logGyro", "", logGyro_func ),
    systemCommand( "logTrain", "", logTrain_func ),
    systemCommand( "logTrigger", "", logTrigger_func ),
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

    commander.setDebugLevel( Commander::DEBUG_VERBOSE );

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
  logType = LOG_ANGLE;
  return true;
}

bool logGyro_func( char *args, Stream *response, void* parent ){
  logType = LOG_GYRO;
  return true;
}

bool logTrain_func( char *args, Stream *response, void* parent ){
  logType = LOG_TRAIN;
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
        /*
        Serial.println( F( " 1 : Barbie" ) );
        Serial.println( F( " 2 : Drink" ) );
        Serial.println( F( " 3 : Movin Cruisin" ) );
        Serial.println( F( " 4 : Lalalala" ) );
        Serial.println( F( " 5 : Rick" ) );
        Serial.println( F( " 6 : We're Not" ) );
        Serial.println( F( " 7 : Vodka" ) );
        Serial.println( F( " 8 : Deja Vu" ) );
        Serial.println( F( " 9 : Titanic" ) );
        Serial.println( F( " 10: Maria" ) );
        Serial.println( F( " 11: Nyan" ) );
        Serial.println( F( " 12: Shrek" ) );
        Serial.println( F( " 13: Gunther" ) );
        Serial.println( F( " 14: R.I.P" ) );
        */
        return true;
    }

    if( player.isPlaying() ){
        Serial.print( F( "Playing!" ) );
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
        case 10:
            player.play( mariaMidi );
            break;
        case 11:
            player.play( nyanMidi );
            break;
        case 12:
            player.play( shrekMidi );
            break;
        case 13:
            player.play( guntherMidi );
            break;
        case 14:
            player.play( ripMidi );
            break;
        default:
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

