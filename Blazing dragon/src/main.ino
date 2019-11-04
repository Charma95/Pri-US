/*
Projet: Le nom du script
Equipe: Votre numero d'equipe
Auteurs: Les membres auteurs du script
Description: Breve description du script
Date: Derniere date de modification
*/

/* ****************************************************************************
Inclure les librairies de functions que vous voulez utiliser
**************************************************************************** */

#include <LibRobus.h> // Essentielle pour utiliser RobUS
#include <ServoControl.h>




/* ****************************************************************************
Variables globales et defines
**************************************************************************** */
// -> defines...
// L'ensemble des fonctions y ont acces

ERROR_T Error = NONE;

/* ****************************************************************************
Vos propres fonctions sont creees ici
**************************************************************************** */
float valeursensor(int sens)
{
   unsigned int valeurbrute;
   unsigned int moyenne_valeurbrute = 0;
   float valeur_cm = 0;
   if (sens == 0 )
   {
   for (int i = 0; i < 100; i++)
  {
    valeurbrute = ROBUS_ReadIR(0);
    moyenne_valeurbrute = (valeurbrute + moyenne_valeurbrute);
  }
    moyenne_valeurbrute =  moyenne_valeurbrute / 100;
    //inverse et ensuite on multiplie par 4600 pour avoir une valeur en cm pour les sensor 0
    valeur_cm = (1.0/moyenne_valeurbrute)*4600.0;
    return (valeur_cm);
   }
   
 
  if ( sens == 1)
  {
  for (int i = 0; i < 100; i++)
  {
    valeurbrute = ROBUS_ReadIR(1);
    moyenne_valeurbrute = (valeurbrute + moyenne_valeurbrute);
  }
    moyenne_valeurbrute =  moyenne_valeurbrute / 100;
    //inverse et ensuite on multiplie par 4600 pour avoir une valeur en cm pour le sensor 1
    valeur_cm = (1.0/moyenne_valeurbrute)*6500.0;
   return (valeur_cm);
  }
delay(1000);
}


/* ****************************************************************************
Fonctions d'initialisation (setup)
**************************************************************************** */
// -> Se fait appeler au debut du programme
// -> Se fait appeler seulement un fois
// -> Generalement on y initilise les varibbles globales
 // Arduino Code to measure distance with a Sharp GP2D12 sensor
// www.swanrobotics.com
#include <Arduino.h>
//char GP2D12;
//char a,b;


void setup()
{
  BoardInit();
  Serial.begin(9600); // Setup communication with computer to present results serial monitor
}

void loop()
{
   unsigned int valeur_1= valeursensor(0);
   unsigned int valeur_2= valeursensor(1);
   
   if (valeur_1 > 30 && valeur_2  > 30)
   {
     MOTOR_SetSpeed(0, 0.2);
     MOTOR_SetSpeed(1, 0.2);  
     delay (200);
   }
   // turn 
   if ( valeur_1 < 30 && valeur_2 > 30 )
   {
     while (ENCODER_Read(1) <= 3200 )
     {
        MOTOR_SetSpeed(0, 0.0);
        MOTOR_SetSpeed(1, 0.2); 
     }   
     delay (1000);
   }
   //turn 
     if ( valeur_2 < 30 && valeur_1 > 30)
   {
    while (ENCODER_Read(0) <= 3200 )
     {
        MOTOR_SetSpeed(0, 0.2);
        MOTOR_SetSpeed(1, 0.0); 
     } 
     delay (100);
   }
   if (valeur_1 < 15 && valeur_2 < 15) 
   {
     while (ENCODER_Read(1) <= 3200 )
     {
        MOTOR_SetSpeed(0, -0.2);
        MOTOR_SetSpeed(1, 0.2); 
     }
      delay(200);
     
   }
  Serial.println(valeursensor(1));
  Serial.println(valeursensor(0));
  delay (200);
  robotReset();
}
  
