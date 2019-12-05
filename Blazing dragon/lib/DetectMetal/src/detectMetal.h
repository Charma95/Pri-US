#ifndef detectMetal_H_ 
#define detectMetal_H_

#include <LibRobus.h>

#define METALSENSOR A6 //Peut être n'importe quelle pin digital de l'arduino

bool metalCheck();
void SOFT_TIMER_setup(uint8_t id);

#endif