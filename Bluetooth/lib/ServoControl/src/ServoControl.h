#pragma once

#include <LibRobus.h>
#include <math.h>

// Defines
#define oneCmClick 133.67

// Structures

//Enums
typedef enum
{
NONE,              // Aucune erreur
INVALID_SPEED,
INVALID_LENGTH,
INVALID_ANGLE,
INVALID_DIRECTION
}ERROR_T; 

// Functions declarations
ERROR_T straightLine(uint8_t distance,float speed);
ERROR_T turn(char direction, uint8_t angle);
void stop(void);
uint16_t angleToClick(uint8_t angle);
ERROR_T halfRoundTrip();
ERROR_T winningDance();
ERROR_T uTurn();
void robotReset();