#include <Arduino.h>
#include "globalResources.hpp"
#include "main.hpp"
#include "commandLine.hpp"
#include "sensor.hpp"

logType_t logType = NO_LOG;

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
}