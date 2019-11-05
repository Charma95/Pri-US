#include <LibRobus.h>
#include "Suiveur.h"

float corr;
int etat;

void SuiveurInit()
{
    corr = 0;
    etat = 1;
}

void LireSuiveur() 
{
    if (analogRead(A5)<30)
        {
            corr = 5;
            etat += etat;
        }
    if ((analogRead(A5)<170) && (analogRead(A5)>130))
        {
            corr = 25;//50
            etat += etat;
        }
    if ((analogRead(A5)<320) && (analogRead(A5)>280))
        {
            corr = 0;
            etat += etat;
        }
    if ((analogRead(A5)<470) && (analogRead(A5)>430))
        {
            corr = -50;
            etat += etat;
        }
    if ((analogRead(A5)<630) && (analogRead(A5)>580))
        {
            corr = -25;//-50
            etat += etat;
        }
    if ((analogRead(A5)<780) && (analogRead(A5)>740))
        {
            corr = 0;
            etat += etat;
        }
    if ((analogRead(A5)<930) && (analogRead(A5)>890))
        {
            corr =  50;//50
            etat += etat;
        }
    if (analogRead(A5)>1020)
        {
            corr = 0;
            etat += etat;
        }
}

void SuitLignes()
{   
    LireSuiveur();
    Serial.print(analogRead(A5));
    Serial.print("  ");
    Serial.println(corr);
    //Serial.println(analogRead(A5));
    if (corr == 5)
    {
        MOTOR_SetSpeed(0,0);
        MOTOR_SetSpeed(1,0);
    }
    else 
    {MOTOR_SetSpeed(0,VMOY);
    MOTOR_SetSpeed(1,(VMOY+((corr)/K)));}
    delay(100);
}