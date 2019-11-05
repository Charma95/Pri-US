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
#include "IRsensor.h"





ERROR_T Error = NONE;


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
  SERVO_Enable(1);

  SERVO_SetAngle(0, 180);
 
}

void loop()
{
  attraperBallon();
  
  avancer(100, 0.4);

  delay(500);
  tourner(90, 1);

  avancer(30, 0.3);
  
  //Serial.println(ROBUS_ReadIR(0));



}
  
