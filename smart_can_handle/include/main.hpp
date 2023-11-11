#ifndef __MAIN_HPP__
#define __MAIN_HPP__

#define TRAIN_BUTTON_PIN 12

// Maximum size of the command in characters.
#define COMMAND_SIZE 30

#define BUZZER_PIN A3
//#define BUZZER_PIN 10

// Update rate of the motion sensor in milliseconds.
#define SENSOR_SAMPLE_PERIOD 75

#define ANGLE_FILTER_RATIO 80

#define GYRO_SENSITIVITY 131 // Degree per seconds

#define GYRO_ARRAY_SIZE 40

#define TOAST_ARRAY_SIZE 30

#define ANGLE_LOW_THRESHOLD 22.5

#define ANGLE_MAP_LOW_BOUND 225
#define ANGLE_MAP_HIGH_BOUND 500

#define BEEP_PERIOD_MAP_LOW_BOUND 1000
#define BEEP_PERIOD_MAP_HIGH_BOUND 50

#define BEEP_FREQ_MAP_LOW_BOUND 440
#define BEEP_FREQ_MAP_HIGH_BOUND 1000


typedef enum{
  NO_LOG,
  LOG_ANGLE,
  LOG_GYRO,
  LOG_TRAIN,
  LOG_TRIGGER,
  LOG_TOAST
} logType_t;


#endif