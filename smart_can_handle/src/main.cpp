#include <Arduino.h>
#include "globalResources.hpp"
#include "main.hpp"
#include "commandLine.hpp"
#include "sensor.hpp"

logType_t logType = NO_LOG;

midiPlayer player( BUZZER_PIN );

unsigned long nextBeep;
unsigned long beepStart;
int beepFrequency = 440;
bool beepActive = false;


uint8_t songID = 0;


void setup() {

    // put your setup code here, to run once:
    Serial.begin( 115200 );

    // MPU6050 init section
    sensorInit();


    // Command line init
    commandLineInit();

    randomSeed(analogRead(0));
    songID = random( trackListSize );

    Serial.print( F( welcomeText ) );
    player.stop();
    player.play( xpMidi );

}

void loop() {
    // put your main code here, to run repeatedly:
    sensorUpdate();
    commandLineUpdate();
    player.update();

    if( !player.isPlaying() ){


        if( beepPeriod != 0 ){

            if( beepActive ){
                if( millis() > nextBeep ){
                    beepActive = false;
                    noTone( buzzerPin );
                    beepStart = millis();
                }
            }

            else{

                nextBeep = beepStart + beepPeriod;
                if( millis() > nextBeep ){
                    beepActive = true;
                    tone( buzzerPin, beepFrequency );
                    nextBeep = millis() + 20;
                }

            }

        }

        else{
            noTone( BUZZER_PIN );
        }


    }



}