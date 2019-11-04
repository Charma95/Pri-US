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
#include "Lift.h"


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
  SERVO_Enable(0);

  trouverBallon();

  float distanceBallon = 0;
  distanceBallon = placerBallonDroit();

  souleverBallon(distanceBallon);

}

void loop()
{

//  int val;
//  GP2D12=read_gp2d12_range(0);
//  a=GP2D12/10;
//  b=GP2D12%10;
//  val=a*10+b;
//  if(val>10&&val<80)
 /*{
  valeurbrute = ROBUS_ReadIR(0);

   Serial.println(valeurbrute);//
   //Serial.print(b,DEC);//
   //Serial.println("cm");//
 }*/
//  else Serial.println("over");//
//  delay(50);
// }
// float read_gp2d12_range(byte pin)
// {
//  int tmp;
//  tmp = analogRead(pin);
//  if (tmp < 3)return -1;
//  return (6787.0 /((float)tmp - 3.0)) - 4.0;
delay(500);
}
  
