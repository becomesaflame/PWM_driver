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

void setPWM(int pwmPercentToWrite);

int getPWM();

void enable();

void disable();

void softStop();


#endif
// END OF FILE
