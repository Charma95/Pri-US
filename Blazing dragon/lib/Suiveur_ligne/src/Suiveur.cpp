#include <LibRobus.h>
#include <Suiveur.h>
#define VMOY 0.4
#define K 100

void SuiveurInit()
{
    Serial.begin(9600);
    struct Suiveur = 
    {
        0,
        1
    };
}

void LireSuiveur() 
{
    if (analogRead(A5)<10 and analogRead(A5)>0);
        {
            Suiveur.corr = 0;
            Suiveur.etat += Suiveur.etat;
        }
    if (analogRead(A5)<160 and analogRead(A5)>150);
        {
            Suiveur.corr = 50;
            Suiveur.etat += Suiveur.etat;
        }
    if (analogRead(A5)<310 and analogRead(A5)>300);
        {
            Suiveur.corr = 0;
            Suiveur.etat += Suiveur.etat;
        }
    if (analogRead(A5)<470 and analogRead(A5)>450);
        {
            Suiveur.corr = -25;
            Suiveur.etat += Suiveur.etat;
        }
    if (analogRead(A5)<615 and analogRead(A5)>600);
        {
            Suiveur.corr = -50;
            Suiveur.etat += Suiveur.etat;
        }
    if (analogRead(A5)<770 and analogRead(A5)>750);
        {
            Suiveur.corr = 0
            Suiveur.etat += Suiveur.etat;
        }
    if (analogRead(A5)<920 and analogRead(A5)>900);
        {
            Suiveur.corr =  50;
            Suiveur.etat += Suiveur.etat;
        }
    if (analogRead(A5)>1020);
        {
            Suiveur.corr = 5;
            Suiveur.etat += Suiveur.etat;
        }
}

void SuitLigne()
{   
    if (Suiveur.corr == 5)
    {
        MOTOR_SetSpeed(0,0);
        MOTOR_SetSpeed(1,0);
    }
    MOTOR_SetSpeed(0,VMOY);
    MOTOR_SetSpeed(1,(VMOY+((Suiveur.corr/Suiveur.etat)/K));
    delay(500);
}