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
    if (analogRead(A9)<30)
        {
            MOTOR_SetSpeed(1,0);
            MOTOR_SetSpeed(0,0);
        }
    if ((analogRead(A9)<170) && (analogRead(A9)>130))
        {
            avancer(3,0.15);
            tourner(92,1);
        }
    if ((analogRead(A9)<320) && (analogRead(A9)>280))
        {
            MOTOR_SetSpeed(1,0);
            MOTOR_SetSpeed(0,0);
        }
    if ((analogRead(A9)<470) && (analogRead(A9)>430))
        {
            tourner(5,1);
        }
    if ((analogRead(A9)<630) && (analogRead(A9)>580))
        {
            avancer(3,0.15);
            tourner(92,0);
        }
    if ((analogRead(A9)<780) && (analogRead(A9)>740))
        {
            MOTOR_SetSpeed(1,0.15);
            MOTOR_SetSpeed(0,0.155);
        }
    if ((analogRead(A9)<930) && (analogRead(A9)>890))
        {
            tourner(5,0);
        }
    if (analogRead(A9)>1020)
        {
            MOTOR_SetSpeed(1,0.15);
            MOTOR_SetSpeed(0,0.155);
        }
        delay(50);
}

void SuitLignes()
{   
    //LireSuiveur();
    Serial.print(analogRead(A9));
    Serial.print("  ");
    Serial.println(corr);
    Serial.println(analogRead(A9));
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
    Serial.println(analogRead(A9));
    while (analogRead(A9) > 1020)
    {
        //LireSuiveur();
        Serial.println(analogRead(A9));
        MOTOR_SetSpeed(0, 0.15);
        MOTOR_SetSpeed(1, 0.15);
        delay(100);
    }

    if ((analogRead(A9)<930) && (analogRead(A9)>890))
    {
        //LireSuiveur();
         while (analogRead(A9) > 1020)
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
        //Serial.println(analogRead(A9));
        //LireSuiveur();
         while (analogRead(A9) > 1020);
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