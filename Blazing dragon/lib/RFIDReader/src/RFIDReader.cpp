#include "RFIDReader.h"


unsigned long getID(MFRC522 mfrc522){
  if ( ! mfrc522.PICC_ReadCardSerial()) { //Since a PICC placed get Serial and continue
    return -1;
  }
  unsigned long hex_num;
  hex_num =  mfrc522.uid.uidByte[0] << 24;
  hex_num += mfrc522.uid.uidByte[1] << 16;
  hex_num += mfrc522.uid.uidByte[2] <<  8;
  hex_num += mfrc522.uid.uidByte[3];
  mfrc522.PICC_HaltA(); // Stop reading
  return hex_num;
}

String LireUID(MFRC522 mfrc522)
{
     // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return "";
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return "";
  }

  //Show UID on serial monitor
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

    
  return content;
}

position TrouverPosition(String uid)
{
    position pos;

    if (uid == " 04 3a 6e 32 c3 58 80")
    {
        Serial.println("A1");
        pos.lettre = 'A';
        pos.chiffre = 1;
    }
    else if (uid == " 04 25 6e 32 c3 58 80")
    {
        pos.lettre = 'A';
        pos.chiffre = 2;
    }
    else if (uid == " 04 27 6e 32 c3 58 80")
    {
        pos.lettre = 'A';
        pos.chiffre = 3;
    }
    else if (uid == " 04 24 6e 32 c3 58 80")
    {
        pos.lettre = 'A';
        pos.chiffre = 4;
    }
    else if (uid == " 04 26 6e 32 c3 58 80")
    {
        pos.lettre = 'A';
        pos.chiffre = 5;
    }
    else if (uid == " 04 c1 6f 32 c3 58 80")
    {
        pos.lettre = 'A';
        pos.chiffre = 6;
    }
    else if (uid == " 04 bf 6f 32 c3 58 80")
    {
        pos.lettre = 'A';
        pos.chiffre = 7;
    }
    else if (uid == " 04 c2 6f 32 c3 58 80")
    {
        pos.lettre = 'B';
        pos.chiffre = 1;
    }
    else if (uid == " 04 c0 6f 32 c3 58 80")
    {
        pos.lettre = 'B';
        pos.chiffre = 2;
    }
    else if (uid == " 04 d6 6f 32 c3 58 80")
    {
        pos.lettre = 'B';
        pos.chiffre = 3;
    }
    else if (uid == " 04 1c 6f 32 c3 58 80")
    {
        pos.lettre = 'B';
        pos.chiffre = 4;
    }
    else if (uid == " 04 20 6f 32 c3 58 80")
    {
        pos.lettre = 'B';
        pos.chiffre = 5;
    }
    else if (uid == " 04 1d 6f 32 c3 58 80")
    {
        pos.lettre = 'B';
        pos.chiffre = 6;
    }
    else if (uid == " 04 34 6f 32 c3 58 80")
    {
        pos.lettre = 'B';
        pos.chiffre = 7;
    }
    else if (uid == " 04 31 6f 32 c3 58 80")
    {
        pos.lettre = 'C';
        pos.chiffre = 1;
    }
    else if (uid == " 04 5a 6f 32 c3 58 80")
    {
        pos.lettre = 'C';
        pos.chiffre = 2;
    }
    else if (uid == " 04 5d 6f 32 c3 58 80")
    {
        pos.lettre = 'C';
        pos.chiffre = 3;
    }
    else if (uid == " 04 5b 6f 32 c3 58 80")
    {
        pos.lettre = 'C';
        pos.chiffre = 4;
    }
    else if (uid == " 04 70 6f 32 c3 58 80")
    {
        pos.lettre = 'C';
        pos.chiffre = 5;
    }
    else if (uid == " 04 6e 6f 32 c3 58 80")
    {
        pos.lettre = 'C';
        pos.chiffre = 6;
    }
    else if (uid == " 04 35 6f 32 c3 58 80")
    {
        pos.lettre = 'C';
        pos.chiffre = 7;
    }
    else if (uid == " 04 32 6f 32 c3 58 80")
    {
        pos.lettre = 'D';
        pos.chiffre = 1;
    }
    else if (uid == " 04 48 6f 32 c3 58 80")
    {
        pos.lettre = 'D';
        pos.chiffre = 2;
    }
    else if (uid == " 04 46 6f 32 c3 58 80")
    {
        pos.lettre = 'D';
        pos.chiffre = 3;
    }
    else if (uid == " 04 49 6f 32 c3 58 80")
    {
        pos.lettre = 'D';
        pos.chiffre = 4;
    }
    else if (uid == " 04 10 6e 32 c3 58 80")
    {
        pos.lettre = 'D';
        pos.chiffre = 5;
    }
    else if (uid == " 04 12 6e 32 c3 58 80")
    {
        pos.lettre = 'D';
        pos.chiffre = 6;
    }
    else if (uid == " 04 0f 6e 32 c3 58 80")
    {
        pos.lettre = 'D';
        pos.chiffre = 7;
    }
    else if (uid == " 04 11 6e 32 c3 58 80")
    {
        pos.lettre = 'E';
        pos.chiffre = 1;
    }
    else if (uid == " 04 1e 6f 32 c3 58 80")
    {
        pos.lettre = 'E';
        pos.chiffre = 2;
    }
    else if (uid == " 04 38 6e 32 c3 58 80")
    {
        pos.lettre = 'E';
        pos.chiffre = 3;
    }
    else if (uid == " 04 3b 6e 32 c3 58 80")
    {
        pos.lettre = 'E';
        pos.chiffre = 4;
    }
    else if (uid == " 04 39 6e 32 c3 58 80")
    {
        pos.lettre = 'E';
        pos.chiffre = 5;
    }
    else if (uid == " 04 4e 6e 32 c3 58 80")
    {
        pos.lettre = 'E';
        pos.chiffre = 6;
    }
    else if (uid == " 04 4c 6e 32 c3 58 80")
    {
        pos.lettre = 'E';
        pos.chiffre = 7;
    }
    else if (uid == " 04 65 6e 32 c3 58 80")
    {
        pos.lettre = 'F';
        pos.chiffre = 1;
    }
    else if (uid == " 04 62 6e 32 c3 58 80")
    {
        pos.lettre = 'F';
        pos.chiffre = 2;
    }
    else if (uid == " 04 64 6e 32 c3 58 80")
    {
        pos.lettre = 'F';
        pos.chiffre = 3;
    }
    else if (uid == " 04 4d 6e 32 c3 58 80")
    {
        pos.lettre = 'F';
        pos.chiffre = 4;
    }
    else if (uid == " 04 4f 6e 32 c3 58 80")
    {
        pos.lettre = 'F';
        pos.chiffre = 5;
    }
    else if (uid == " 04 77 6e 32 c3 58 80")
    {
        pos.lettre = 'F';
        pos.chiffre = 6;
    }
    else if (uid == " 04 79 6e 32 c3 58 80")
    {
        pos.lettre = 'F';
        pos.chiffre = 7;
    }
    else if (uid == " 04 76 6e 32 c3 58 80")
    {
        pos.lettre = 'G';
        pos.chiffre = 1;
    }
    else if (uid == " 04 78 6e 32 c3 58 80")
    {
        pos.lettre = 'G';
        pos.chiffre = 2;
    }
    else if (uid == " 04 63 6e 32 c3 58 80")
    {
        pos.lettre = 'G';
        pos.chiffre = 3;
    }
    else if (uid == " 04 ff 6f 32 c3 58 80")
    {
        pos.lettre = 'G';
        pos.chiffre = 4;
    }
    else if (uid == " 04 14 6f 32 c3 58 81")
    {
        pos.lettre = 'G';
        pos.chiffre = 5;
    }
    else if (uid == " 04 12 6f 32 c3 58 81")
    {
        pos.lettre = 'G';
        pos.chiffre = 6;
    }
    else if (uid == " 04 15 6f 32 c3 58 81")
    {
        pos.lettre = 'G';
        pos.chiffre = 7;
    }
    else
    {
        pos.lettre = '0';
        pos.chiffre  = 0;
    }
    
    

    return pos;
}