/*
Projet: Le nom du script
Equipe: Votre numero d'equipe
Auteurs: Les membres auteurs du script
Description: Breve description du script
Date: Derniere date de modification
*/


#include <LibRobus.h> // Essentielle pour utiliser RobUS
#include <ServoControl.h>
#include "Mouvement.h"
#include "Lift.h"
#include "Bluetooth.h"
#include "IRsensor.h"
#include <Arduino.h>
#include <RGB_Sensor.h>


/* ****************************************************************************
Variables globales et defines
**************************************************************************** */
// -> defines...
// L'ensemble des fonctions y ont accesdef

#define ONEMINUTE 60000 /* Softimer use milis()*/



uint16_t red, green, blue, c, colorTemp, lux;
String msg = "Le bluetooth est fonctionnel Lionel\n";
ERROR_T Error = NONE;


void bluetoothTest()
{
 BLUETOOTH_println(msg);   /* ne fonctionne pas faudrait voir les pins*/
  //Serial.print(msg);
  delay(2000);
}
void robotA(void)
{
  if(ROBUS_IsBumper(3))    /* If Tessier fessed the back bumper */
  {
    /* Placer robot dans la bonne couleur*/
      tourner(69, 1);
      avancer(69, 0.4);
      tourner(69, 0);
    /* Soulever le ballon */
      souleverBallon(10);
    /* Trouver une ligne */
      tourner(180,1);
      if(IsLinedetected())
      {
        /* Sniffer la ligne */
        //fonction de sniffage a Yorick
      }
      if(centerFound())
      {
        /* Déposer le ballon au centre */
      }
  }
  
}

/* ****************************************************************************
Fonctions d'initialisation (setup)
**************************************************************************** */
// -> Se fait appeler au debut du programme
// -> Se fait appeler seulement un fois
// -> Generalement on y initilise les varibbles globales
 // Arduino Code to measure distance with a Sharp GP2D12 sensor
// www.swanrobotics.com

void setup()
{
  BoardInit();
  Serial.begin(9600); // Setup communication with computer to present results serial monitor
  Serial2.begin(9600);
  
  //Serial.println(ROBUS_ReadIR(0));

void loop()
{
//bluetoothTest();
delay(10);     /* Delai pour décharger le cpu*/
}
  
