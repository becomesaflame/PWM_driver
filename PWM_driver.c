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
static int pwmPercent[6];

// raw PWM rate
static float pwmRaw[6];

// Max bits for PWM 
const float bitResolution = pow(2,10)-1;

// Boolean 
static int enabled;

//-------------------------------------------
// Functions
//-------------------------------------------

// // Initialization function
// void initializePWM(){
//   
// }

// Set raw PWM outputs from percents
void setPWM(int pwmPercentToWrite[]){
  if (enabled){
    pwmPercent = pwmPercentToWrite;
    for (int i = 0; i < 6; i++) { 
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
  for (int i = 0; i < 6; i++) { 
    for (int j; j = pwmPercent[i]; j--){
      pwmPercent[i]--;
      pwmRaw[i] = percent2raw(pwmPercent[i]);
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
  // Make sure both sides of any valve aren't opening
  if ((PWM_value[0] && PWM_value[1]) || 
      (PWM_value[2] && PWM_value[3]) ||
      (PWM_value[4] && PWM_value[5])) {
    softStop();
    Serial.print("ERROR - tried to open both sides of a valve");
  } 
  else {
    analogWrite(kneePWM1_retract, PWM_value[0]);
    analogWrite(kneePWM2_extend,  PWM_value[1]);
    analogWrite(thighPWM1_up,     PWM_value[2];
    analogWrite(thighPWM2_down,   PWM_value[3];
    analogWrite(hipPWM1_forward,  PWM_value[4];
    analogWrite(hipPWM2_reverse,  PWM_value[5];
  }
  #endif
}

// Convert PWM percent to raw PWM
static float percent2raw(float percent){
  float raw = (percent/100) * bitResolution;
}

// END OF FILE
