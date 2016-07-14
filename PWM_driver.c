//
//    FILE: PWM_driver.c
//  AUTHOR: Spark
// VERSION: 0.0.0
// PURPOSE: PWM driver
//     URL: 
//
// LICENSE: 
//

#include <stdlib.h>
#include "PWM_driver.h"

//-------------------------------------------
// Local Variables
//-------------------------------------------

// PWM rate expressed as int from 0-100
static int pwmPercent[3];

// raw PWM rate
static float pwmRaw[3];

// Max bits for PWM 
const float bitResolution = pow(2,10)-1;

// Boolean 
static int enabled;

//-------------------------------------------
// Functions
//-------------------------------------------

// Initialization function
void initializePWM(){
  
}

// Set raw PWM outputs from percents
void setPWM(int pwmPercentToWrite[]){
  if (enabled){
    pwmPercent = pwmPercentToWrite;
    for (int i = 0; i < 3; i++) { 
      pwmRaw[i] = percent2raw(pwmPercent[i]);
    }
    updatePWM();
  }
}

// Return the PWM rate as a percent (0-100)
int * getPWM(){
  return pwmPercent;
}

// Enable control of PWM's for this leg
void enable(){
  enabled = true;
  updatePWM();
}

// Disable control of PWM's for this leg
void disable(){
  softStop();
  enabled = false;
}

// Ramp the PWM to 0
void softStop(){
  for (int i; i = pwmPercent; i--){
    for (int j = 0; j < 3; j++) { 
      pwmPercent[j]--;
      pwmRaw[j] = percent2raw(pwmPercent[j]);
    }
    #ifdef ARDUINO
    delay(1); // pause 1ms
    // Note that this function will block
    // execution of main loop 
    #endif
  }
}

//-------------------------------------------
// Local functions
//-------------------------------------------

// interface to physical PWM output
static void updatePWM(){
  #ifdef ARDUINO
  // Arduino output
  // Make sure both sides of a valve aren't opening
  if (kneePWM2_extend && kneePWM1_retract) {
    softStop();
    Serial.print("ERROR - tried to open both sides of a valve");
  } 
  else {
    analogWrite(kneePWM2_extend, PWM_value[2]);
  }
  #endif
}

// Convert PWM percent to raw PWM
static float percent2raw(float percent){
  float raw = (percent/100) * bitResolution;
}

// END OF FILE
