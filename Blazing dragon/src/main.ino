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
#include "defiCombattant.h"
#include "RFIDReader.h"
#include "detectMetal.h"
#include <Arduino.h>
#include <RGB_Sensor.h>
#include <SPI.h>
#include <MFRC522.h>


/* ****************************************************************************
Variables globales et defines
**************************************************************************** */
// -> defines...
// L'ensemble des fonctions y ont accesdef

#define ONEMINUTE 60000 /* Softimer use milis()*/
#define RST_PIN         2          // Configurable, see typical pin layout above
#define SS_PIN          53         // Configurable, see typical pin layout above



uint16_t red, green, blue, c, colorTemp, lux;
String msg = "Le bluetooth est fonctionnel Lionel\n";
ERROR_T Error = NONE;
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance


void bluetoothTest()
{
 BLUETOOTH_println(msg);   /* ne fonctionne pas faudrait voir les pins*/
  //Serial.print(msg);
  delay(2000);
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
  SuiveurInit();
  Serial.begin(9600); // Setup communication with computer to present results serial monitor
  Serial2.begin(9600);

  SPI.begin();			// Init SPI bus
	mfrc522.PCD_Init();		// Init MFRC522
	delay(4);				// Optional delay. Some board do need more time after init to be ready, see Readme
	mfrc522.PCD_DumpVersionToSerial();	// Show details of PCD - MFRC522 Card Reader details
	Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

void loop()
{
  delay(2000);
  while (analogRead(A6) > 200)
  {
    LireSuiveur();
    Serial.println("Recherche de mines");
    BLUETOOTH_println("Recherche de mines");
  }
  
  Serial.println("Mine detectee");
  BLUETOOTH_println("Mine detectee");
  while(!ROBUS_IsBumper(1))
  {
    MOTOR_SetSpeed(0, 0);
    MOTOR_SetSpeed(1, 0);
  }
  String uid = "";
  while(uid == "")
  {
    LireSuiveur();
    uid = LireUID(mfrc522);
    Serial.println("En attente de la position");
    BLUETOOTH_println("En attente de la position");
  }
  struct position pos;
  pos = TrouverPosition(uid);
  Serial.print("La mine se trouve dans la case ");
  Serial.print(pos.lettre);
  Serial.println(pos.chiffre);
  BLUETOOTH_print("La mine se trouve dans la case ");
  BLUETOOTH_print((String) pos.lettre);
  BLUETOOTH_println((String) pos.chiffre);
  MOTOR_SetSpeed(0, 0);
  MOTOR_SetSpeed(1, 0);
  //BLUETOOTH_println("puce detectee");
  delay(2000);

  /*String uid = "";
  uid = LireUID(mfrc522);
  struct position pos;
  pos = TrouverPosition(uid);
  BLUETOOTH_println(uid);
  BLUETOOTH_print("La mine se trouve dans la case ");
  BLUETOOTH_print((String) pos.lettre);
  BLUETOOTH_println((String) pos.chiffre);
  delay(1000);*/

}
  
