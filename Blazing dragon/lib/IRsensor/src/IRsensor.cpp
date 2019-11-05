#include "IRsensor.h"
#include <LibRobus.h>


float valeursensor(int sens)
{
   unsigned int valeurbrute;
   unsigned int moyenne_valeurbrute = 0;
   float valeur_cm = 0;
   float cstajustement;
   if (sens == 0 )
   {
       cstajustement=4750.0;
   }
   
   if (sens == 1 )
   {
       cstajustement=2375.0;
   }


   for (int i = 0; i < 100; i++)
  {
    valeurbrute = ROBUS_ReadIR(sens);
    moyenne_valeurbrute = (valeurbrute + moyenne_valeurbrute);
  }
    moyenne_valeurbrute =  moyenne_valeurbrute / 100.0;
    //inverse et ensuite on multiplie par 4600 pour avoir une valeur en cm 
    valeur_cm = (1.0/moyenne_valeurbrute)*cstajustement;
    return (valeur_cm);
}

void testIR ()
{
Serial.print("gauche : ");
Serial.print(ROBUS_ReadIR(0));
Serial.print("droite : ");
Serial.print(ROBUS_ReadIR(1)*2);
Serial.print("\n");
}