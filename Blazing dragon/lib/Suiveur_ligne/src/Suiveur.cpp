#include <LibRobus.h>

void SuiveurInit()
{
    Serial.begin(9600);
}

int LireSuiveur() 
{
    Serial.print(analogRead(A0));
}