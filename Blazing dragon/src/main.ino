/*
Projet: Le nom du script
Equipe: Votre numero d'equipe
Auteurs: Les membres auteurs du script
Description: Breve description du script
Date: Derniere date de modification
*/


#include <LibRobus.h> // Essentielle pour utiliser RobUS
#include "ServoControl.h"
#include "Mouvement.h"
#include "Lift.h"
#include "Bluetooth.h"
#include "Suiveur.h"
#include "IRsensor.h"
#include <Arduino.h>
#include <RGB_Sensor.h>


/* ****************************************************************************
Variables globales et defines
**************************************************************************** */
// -> defines...
// L'ensemble des fonctions y ont accesdef




uint16_t red, green, blue, c, colorTemp, lux;
String msg = "A7\n";
ERROR_T Error = NONE;


void bluetoothTest()
{
 BLUETOOTH_println(msg);   
  //Serial.print(msg);
  delay(2000);
}
void robotA(int couleur)
{
  if(ROBUS_IsBumper(3))    /* If Tessier fessed the back bumper */
  {
    /* ouvrir la pince */
    SERVO_SetAngle(0, ANGLE_OUVERT);

    /* Placer robot dans la bonne couleur*/
    avancer(39, 0.3);

    switch(couleur)
    {
      case ROUGE:
      tourner(45, 0);
      break;
      case VERT:
      tourner(45, 1);
      break;
      case BLEU:
      tourner(135, 1);
      break;
      case JAUNE:
      tourner(135, 0);
      break;
      default: break;
    }
    avancer(120, 0.3);
    /* Soulever le ballon */
    attraperBallon(ROBOT_A);
    /* Retourner au centre */
    tourner(180,0);
    avancer(125, 0.3);

    /* Deposer la balle */
    lacherBallon(ROBOT_A);

    /* reculer */
    allerscacher(couleur);
    
    delay(120000);
  }
  
}

void robotB(int couleur)
{
  //delay(60000);
  SERVO_SetAngle(0, ANGLE_OUVERTB);
  // aller se placer vis à vis la couleur
  /*switch(couleur)
    {
      case ROUGE:
      tourner(45, 0);
      break;
      case VERT:
      tourner(45, 1);
      break;
      case BLEU:
      tourner(135, 1);
      break;
      case JAUNE:
      tourner(135, 0);
      break;
      default: break;
    }*/
    // trouver le ballon et le prendre
    int angleTourne = 0;
    angleTourne = attraperBallon(ROBOT_B);
    // se réorienter
    if (angleTourne < -15)
    {
      // tourner à droite
      angleTourne *= -1;
      tourner(angleTourne + 16, 1);
    }
    else if (angleTourne > 15)
    {
      // tourner à gauche
      tourner(angleTourne + 13, 0);
    }
    else if (angleTourne < 0)
    {
      angleTourne *= -1;
      tourner(angleTourne + 8, 1);
    }
    else if (angleTourne > 0)
    {
      // tourner à gauche
      tourner(angleTourne + 5, 0);
    }

    
    
    // avancer jusque dans le but
    avancer(125, 0.3);

    // relacher le ballon
    lacherBallon(ROBOT_B);
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
}

void loop()
{
  bluetoothTest();
  delay(2000);
}
  
