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

  SERVO_SetAngle(0, ANGLE_SOL);
  SERVO_SetAngle(1, 180);
 
}

void loop()
{
  /*int distanceBallon = 0;

  souleverBallon(distanceBallon);

  avancer(30, 0.2);

  delay(1000);

  deposerBallon();

  delay(1000);

  //testIR();
  allerscacher (-30.0);*/

  delay(1000);
  SERVO_SetAngle(1, 140);



}
  
