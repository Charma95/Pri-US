#include "MineTrace.h"

void Demineur(MFRC522 mfrc522)
{
    String position = "";
    delay(2000);
    
    while (analogRead(A6) > 200)
    {
        LireSuiveur();
        digitalWrite(GREEN_PIN, LOW);
        digitalWrite(RED_PIN, HIGH);
    }
    
    
    while(BLUETOOTH_read() != "1")
    {
        MOTOR_SetSpeed(0, 0);
        MOTOR_SetSpeed(1, 0);
        while(analogRead(A6) < 200)
        {
        digitalWrite(GREEN_PIN, HIGH);
        digitalWrite(RED_PIN, LOW);
        }
        digitalWrite(GREEN_PIN, LOW);
        digitalWrite(RED_PIN, HIGH);
        
    }

    String uid = "";
    while(uid == "")
    {
        LireSuiveur();
        uid = LireUID(mfrc522);
    }
    struct position pos;
    pos = TrouverPosition(uid);
    position = (String) pos.lettre + (String) pos.chiffre;
    BLUETOOTH_println(position);
    delay(50);
    BLUETOOTH_println(position);
    delay(50);
    BLUETOOTH_println(position);
    MOTOR_SetSpeed(0, 0);
    MOTOR_SetSpeed(1, 0);
    delay(2000);
}