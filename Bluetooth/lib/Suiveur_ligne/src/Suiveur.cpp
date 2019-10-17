#include <LibRobus.h>
#include <Arduino.h>

void SuiveurInit()
{
    Serial.begin(9600);
}

int LireSuiveur() 
{
    Serial.Print(analogRead(A0));
}