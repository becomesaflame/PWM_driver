//
//    FILE: PWM_driver.h
//  AUTHOR: Spark
// VERSION: 0.0.0
// PURPOSE: PWM driver
//     URL: 
//
// LICENSE: 
//

#ifndef PWM_driver_h
#define PWM_driver_h

#define ARDUINO

// Pin definitions
const int kneePWM1_retract_pin = 5;
const int kneePWM2_extend_pin  = 6;
const int thighPWM1_up_pin     = 4;
const int thighPWM2_down_pin   = 3;
const int hipPWM1_forward_pin  = 9;
const int hipPWM2_reverse_pin  = 10;

// void initializePWM();

void setPWM(int pwmPercentToWrite[]);

int * getPWM();

void enable();

void disable();

void softStop();


#endif
// END OF FILE
