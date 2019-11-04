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
void maFonction()
{
  // code
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
unsigned int valeurbrute;
void setup()
{
  BoardInit();
  Serial.begin(9600); // Setup communication with computer to present results serial monitor
}


/* ****************************************************************************
Fonctions de boucle infini (loop())
**************************************************************************** */
// -> Se fait appeler perpetuellement suite au "setup"

void loop()
{
//  int val;
//  GP2D12=read_gp2d12_range(0);
//  a=GP2D12/10;
//  b=GP2D12%10;
//  val=a*10+b;
//  if(val>10&&val<80)
 {
  valeurbrute = ROBUS_ReadIR(0);

   Serial.println(valeurbrute);//
   //Serial.print(b,DEC);//
   //Serial.println("cm");//
 }
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
  // halfRoundTrip();
  // uTurn();
  // robotReset(); 
  // straightLine(100, 0.3);
  // robotReset();
  // straightLine(100, 0.3);
  
