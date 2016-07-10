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
static int pwmRaw[3];

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
  #endif
}


// END OF FILE
