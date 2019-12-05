#pragma once

#include <String.h>
#include "MFRC522.h" 

unsigned long getID(MFRC522 mfrc522);

String LireUID(MFRC522 mfrc522);

struct position {
    char lettre;
    uint8_t chiffre;
};

extern position TrouverPosition(String uid);
