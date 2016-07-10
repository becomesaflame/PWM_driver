//
//    FILE: PWM_driver.c
//  AUTHOR: Spark
// VERSION: 0.0.0
// PURPOSE: PWM driver
//     URL: 
//
// LICENSE: 
//

#include "PWM_driver.h"
#include <stdlib.h>

// PWM rate expressed as int from 0-100
static int pwmPercent[3];

// raw PWM rate
static int pwmRaw[3];

// Max bits for PWM 
const float bitResolution = pow(2,10)-1;

// Boolean 
static int enabled;

// Initialization function
void initializePWM(){
  
}

// Set raw PWM outputs from percents
void setPWM(int pwmPercentToWrite[3]){
  if (enabled){
    for (int i = 0; i < 3; i++) { 
      pwmPercent[i] = pwmPercentToWrite[i];
      pwmRaw[i] = (pwmPercent[i]/100) * bitResolution;
      updatePWM();
    }
  }
}

// Return the PWM rate as a percent (0-100)
int * getPWM(){
  return pwmPercent;
}

void enable(){
  enabled = true;
  updatePWM();
}

void disable(){
  softStop();
  enabled = false;
}

// Ramp the PWM to 0
void softStop(){
  #ifdef ARDUINO
  unsigned long rampTime = millis();
  #endif

  for (int i; i = pwmPercent; i--){
    for (int i = 0; i < 3; i++) { 
      pwmPercent[i]--;
      #ifdef ARDUINO
      delay(1);
      #endif
    }
  }
}

// interface to physical PWM output
static void updatePWM(){
  // Arduino output
  
}


// END OF FILE
