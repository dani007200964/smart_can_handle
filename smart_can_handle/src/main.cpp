#include <Arduino.h>
#include "globalResources.hpp"
#include "main.hpp"
#include "commandLine.hpp"
#include "sensor.hpp"

logType_t logType = NO_LOG;

midiPlayer player( BUZZER_PIN );

int beepPeriodOn = 20;
int beepPeriodOff = 1000;
unsigned long beepPeriod = beepPeriodOff;
int beepFrequency = 440;
bool beepActive = false;
unsigned long beepTimer = 0;


void setup() {
    // put your setup code here, to run once:
    Serial.begin( 115200 );
    sensorInit();
    commandLineInit();

    Serial.print( F( welcomeText ) );

}

void loop() {
    // put your main code here, to run repeatedly:
    sensorUpdate();
    commandLineUpdate();
    player.update();

    if( beepPeriodOff > 0 ){

        if( ( millis() - beepTimer ) > beepPeriod ){

            beepActive = !beepActive;

            if( beepActive ){
                tone( BUZZER_PIN, beepFrequency );
                beepPeriod = beepPeriodOn;
            }

            else{
                noTone( BUZZER_PIN );
                beepPeriod = beepPeriodOff;
            }

            beepTimer = millis();
            //Serial.println( "Beep" );

        }

    }


}