#include <Arduino.h>
#include <LibRobus.h> 
#include "detectMetal.h"

char pastState = 0;

bool metalCheck(void){
    if (analogRead(A6) < 500) return true;      //Le capteur est actif bas
    else return false;
}

void SOFT_TIMER_setup(uint8_t id){
//SOFT_TIMER_SetCallback(id, metalCheck);
SOFT_TIMER_SetDelay(id, 10); 
}