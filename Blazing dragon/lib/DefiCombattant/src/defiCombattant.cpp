#include "defiCombattant.h"

void robotA(int couleur)
{
  if(ROBUS_IsBumper(3))    /* If Tessier fessed the back bumper */
  {
    /* Placer robot dans la bonne couleur*/
    avancer(39, 0.3);

    switch(couleur)
    {
      case ROUGE:
      tourner(45, 0);
      avancer(105, 0.3);
      attraperBallon(ROBOT_A);
      tourner(200,0);
      avancer(105, 0.3);
      break;
      case VERT:
      tourner(45, 1);
      avancer(105, 0.3);
      attraperBallon(ROBOT_A);
      tourner(200,0);
      avancer(105, 0.3);
      break;
      case BLEU:
      tourner(150, 1);
      avancer(105, 0.3);
      attraperBallon(ROBOT_A);
      tourner(193,0);
      avancer(105, 0.3);
      break;
      case JAUNE:
      tourner(146, 0);
      avancer(105, 0.3);
      attraperBallon(ROBOT_A);
      tourner(200,0);
      avancer(105, 0.3);
      break;
      default: break;
    }

    /* Deposer la balle */
    lacherBallon(ROBOT_A);

    /* reculer */
    allerscacher(couleur);
    
    delay(120000);
  }
  
}

void robotB(int couleur)
{
  if (ROBUS_IsBumper(3))
  {
    switch(couleur)
    {
      case ROUGE:
      tourner(93, 0);
      avancer(39,0.3);
      tourner(90,1);
      avancer(93,0.3);
      tourner(141,1);
      avancer(35,0.3);
      break;
      case VERT:
      tourner(90, 1);
      avancer(39,0.3);
      tourner(90,0);
      avancer(93,0.3);
      tourner(135,0);
      avancer(45,0.3);
      break;
      case BLEU:
      tourner(90,1);
      avancer(39,0.3);
      tourner(135,0);
      avancer(45,0.3);
      break;
      case JAUNE:
      tourner(90,0);
      avancer(39,0.3);
      tourner(135,1);
      avancer(45,0.3);
      break;
      default: break;
    }
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
  //delay(60000);
  // aller se placer vis à vis la couleur
  
}