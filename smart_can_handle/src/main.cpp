#include <Arduino.h>
#include "main.hpp"
#include "commandLine.hpp"

logType_t logType = NO_LOG;

void setup() {
  // put your setup code here, to run once:
  Serial.begin( 115200 );
  commandLineInit();

  Serial.print( F( welcomeText ) );
}

void loop() {
  // put your main code here, to run repeatedly:
  commandLineUpdate();
}