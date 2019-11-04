#include "IRsensor.h"
#include <LibRobus.h>


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