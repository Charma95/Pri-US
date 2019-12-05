#include "rfid.h"

#define SS_PIN 53
#define RST_PIN 5
/* Function's declaration */

int readNFC(void);
bool writeNFC(int address);