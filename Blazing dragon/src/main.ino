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
#include "MineTrace.h"
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
  pinMode(GREEN_PIN, OUTPUT); // vert
  pinMode(RED_PIN, OUTPUT); 

  SPI.begin();			// Init SPI bus
	mfrc522.PCD_Init();		// Init MFRC522
	delay(4);				// Optional delay. Some board do need more time after init to be ready, see Readme
	mfrc522.PCD_DumpVersionToSerial();	// Show details of PCD - MFRC522 Card Reader details
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(RED_PIN, HIGH);
}

void loop()
{
  if (BLUETOOTH_read() == "1")
  {
    Demineur(mfrc522);
  }  
  /*String position = "";
  delay(2000);
  
  while (analogRead(A6) > 200)
  {
    LireSuiveur();
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(RED_PIN, HIGH);
  }
  
  
  while(BLUETOOTH_read() != "1")
  {
    MOTOR_SetSpeed(0, 0);
    MOTOR_SetSpeed(1, 0);
    while(analogRead(A6) < 200)
    {
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(RED_PIN, LOW);
    }
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(RED_PIN, HIGH);
    
  }

  String uid = "";
  while(uid == "")
  {
    LireSuiveur();
    uid = LireUID(mfrc522);
  }
  struct position pos;
  pos = TrouverPosition(uid);
  position = (String) pos.lettre + (String) pos.chiffre;
  BLUETOOTH_println(position);
  delay(50);
  BLUETOOTH_println(position);
  delay(50);
  BLUETOOTH_println(position);
  MOTOR_SetSpeed(0, 0);
  MOTOR_SetSpeed(1, 0);
  delay(2000);*/

  /*String uid = "";
  uid = LireUID(mfrc522);
  struct position pos;
  pos = TrouverPosition(uid);
  BLUETOOTH_println(uid);
  BLUETOOTH_print("La mine se trouve dans la case ");
  BLUETOOTH_print((String) pos.lettre);
  BLUETOOTH_println((String) pos.chiffre);
  delay(1000);*/

  /*if ( ! mfrc522.PICC_IsNewCardPresent()) {
		return;
	}

	// Select one of the cards
	if ( ! mfrc522.PICC_ReadCardSerial()) {
		return;
	}

	// Dump debug info about the card; PICC_HaltA() is automatically called
	mfrc522.PICC_DumpToSerial(&(mfrc522.uid));*/

}
  
