#include "sensor.hpp"

// MPU6050 Sesnor Object.
MPU6050 motionSensor;

// These variables will hold the current acceleration data.
int16_t accX = 0;
int16_t accY = 0;
int16_t accZ = 0;

// These variables will hold the current angular velocity data.
int16_t gyroX = 0;
int16_t gyroY = 0;
int16_t gyroZ = 0;

const float DEG2RAD = PI / 180.0f;
const float RAD2DEG = 180.0f / PI;

bool sensorInitialized = false;

float angle;

// Gyro data for wiggle recognition.
int16_t gyroArray[ GYRO_ARRAY_SIZE ] = { 0 };

unsigned long sensorTimerStart = 0;

void sensorInit(){

    Wire.setClock( 400000  );
    Wire.begin();


    // initialize MPU6050
    Serial.println( F( "Initializing MPU6050..." ) );
    motionSensor.initialize();

    if( motionSensor.testConnection() ){
      Serial.println( " [ OK ]" );
      sensorInitialized = true;
    }

    else{
      Serial.println( " [ ERROR ]" );
    }

}

void sensorUpdate(){

    float accX_f;
    float accY_f;
    float accZ_f;
    
    float accDotProduct = 0.0;
    float denominator;

    int i;

    if( !sensorInitialized ){
        return;
    }

    if( ( millis() - sensorTimerStart ) <= SENSOR_SAMPLE_PERIOD ){
        return;
    }

    motionSensor.getMotion6( &accX, &accY, &accZ, &gyroX, &gyroY, &gyroZ );

    accX_f = accZ / 1000.0;
    accY_f = accY / 1000.0;
    accZ_f = accX / 1000.0;

    // accX_f * unitX + accY_f * unitY + accZ_f * unitZ
    // unitX = 0.0;
    // unitY = 0.0;
    // unitZ = 1.0;
    // unit is for unit vector which is standing upwards.
    accDotProduct = accZ_f;

    denominator = sqrt( accX_f * accX_f + accY_f * accY_f + accZ_f * accZ_f );

    angle = acos( accDotProduct / denominator ) * RAD2DEG;

    for( i = 0; i < GYRO_ARRAY_SIZE - 1; i++ ){
        gyroArray[ i ] = gyroArray[ i + 1 ];
    }
    gyroArray[ i ] = gyroZ / GYRO_SENSITIVITY;


    sensorTimerStart = millis();

    if( logType != NO_LOG ){

        if( Serial.available() > 0 ){
            Serial.read();
            logType = NO_LOG;
            Serial.print( F( "$: " ) );
        }

        switch( logType ){
            case LOG_ANGLE:
                Serial.println( angle );
                break;
            case LOG_GYRO:
                Serial.println( gyroArray[ GYRO_ARRAY_SIZE - 1 ] );
                break;
            case LOG_TRAIN:
                printTrainData();
                break;
            default:
                break;
        }

    }

}

void printTrainData(){
  int i;

  Serial.print( millis() % 1000 );
    Serial.print( ", " );

  for( i = 0; i < GYRO_ARRAY_SIZE; i++ ){
    Serial.print( gyroArray[ i ] );
    Serial.print( ", " );
  }
  Serial.println( "idle" );
}
