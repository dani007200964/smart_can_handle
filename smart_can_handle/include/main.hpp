#ifndef __MAIN_HPP__
#define __MAIN_HPP__

#define TRAIN_BUTTON_PIN 3

// Maximum size of the command in characters.
#define COMMAND_SIZE 30

#define BUZZER_PIN A3

// Update rate of the motion sensor in milliseconds.
#define SENSOR_SAMPLE_PERIOD 75

#define ANGLE_FILTER_RATIO 80

#define GYRO_SENSITIVITY 131 // Degree per seconds

#define GYRO_ARRAY_SIZE 40


typedef enum{
  NO_LOG,
  LOG_ANGLE,
  LOG_GYRO,
  LOG_TRAIN
} logType_t;


#endif