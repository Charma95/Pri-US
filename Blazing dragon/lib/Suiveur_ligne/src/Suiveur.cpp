#include <LibRobus.h>
#include "Suiveur.h"
#include "Mouvement.h"

float corr;
int etat;
int milieu;

void SuiveurInit()
{
    corr = 0;
    etat = 1;
    milieu = 0;
}

void LireSuiveur() 
{
    Serial.println(analogRead(A5));
    if (analogRead(A5)<30)
        {
            MOTOR_SetSpeed(1,0.15);
            MOTOR_SetSpeed(0,0.155);
        }
    if ((analogRead(A5)<170) && (analogRead(A5)>130))
        {
            avancer(3,0.15);
            tourner(92,1);
        }
    if ((analogRead(A5)<320) && (analogRead(A5)>280))
        {
            MOTOR_SetSpeed(1,0);
            MOTOR_SetSpeed(0,0);
        }
    if ((analogRead(A5)<470) && (analogRead(A5)>430))
        {
            tourner(5,1);
        }
    if ((analogRead(A5)<630) && (analogRead(A5)>580))
        {
            avancer(3,0.15);
            tourner(92,0);
        }
    if ((analogRead(A5)<780) && (analogRead(A5)>740))
        {
            MOTOR_SetSpeed(1,0.15);
            MOTOR_SetSpeed(0,0.155);
        }
    if ((analogRead(A5)<930) && (analogRead(A5)>890))
        {
            tourner(5,0);
        }
    if (analogRead(A5)>1020)
        {
            MOTOR_SetSpeed(1,0.15);
            MOTOR_SetSpeed(0,0.155);
        }
}

void SuitLignes()
{   
    //LireSuiveur();
    Serial.print(analogRead(A5));
    Serial.print("  ");
    Serial.println(corr);
    Serial.println(analogRead(A5));
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

void enligner(int direction)
{
    // avancer tant qu'il ne croise pas de ligne
    //LireSuiveur();
    Serial.println(analogRead(A5));
    while (analogRead(A5) > 1020)
    {
        //LireSuiveur();
        Serial.println(analogRead(A5));
        MOTOR_SetSpeed(0, 0.15);
        MOTOR_SetSpeed(1, 0.15);
        delay(100);
    }

    if ((analogRead(A5)<930) && (analogRead(A5)>890))
    {
        //LireSuiveur();
         while (analogRead(A5) > 1020)
        {
            MOTOR_SetSpeed(0, 0.15);
            MOTOR_SetSpeed(1, 0.15);
            //LireSuiveur();
            delay(100);
        }
        MOTOR_SetSpeed(0,0);   
        MOTOR_SetSpeed(1,0); 
        while(milieu == 0)
        {
            // tourner à droite
            //LireSuiveur();
            MOTOR_SetSpeed(0, 0.15);
            MOTOR_SetSpeed(1, -0.15);
        }
         
    }
    else
    {
        //Serial.println(analogRead(A5));
        //LireSuiveur();
         while (analogRead(A5) > 1020);
        {
            MOTOR_SetSpeed(0, 0.15);
            MOTOR_SetSpeed(1, 0.15);
            //LireSuiveur();
            delay(100);
        }
        MOTOR_SetSpeed(0,0);   
        MOTOR_SetSpeed(1,0); 
        while(milieu == 0)
        {
            // tourner à gauche
            //LireSuiveur();
            MOTOR_SetSpeed(1, 0.15);
            MOTOR_SetSpeed(0, -0.15);
        }
    }
    Serial.println("robot enligné");
}