

#include <LibRobus.h>
#include <Math.h>
#include "Lift.h"
#include "Mouvement.h"
#include "IRsensor.h"

void trouverBallon()
{
    float distanceG = 0, distanceD = 0;

    distanceG = valeursensor(0);
    distanceD = valeursensor(1);

    float targetPulse360 = 0;
    targetPulse360 = DR_R*COEFF_ANGLE*3200/(7.62);

    while (distanceG > 20 || distanceD > 20)
    {
        MOTOR_SetSpeed(0, 0.15);
        MOTOR_SetSpeed(1, -0.15);

        if (ENCODER_Read(0) == targetPulse360) 
        {
            ENCODER_Reset(0);
            ENCODER_Reset(1);
            MOTOR_SetSpeed(0, 0);
            MOTOR_SetSpeed(1, 0);
            avancerVerifierBalle(0, 0.15);
        }

        distanceG = valeursensor(0);
        distanceD = valeursensor(1);
    }
}

// la distance est en cm
void souleverBallon(float distance)
{
    // avancer jusqu'au ballon
    int distanceG = ROBUS_ReadIR(0), distanceD = ROBUS_ReadIR(1)*2;
    int ajout = 0.1;

    MOTOR_SetSpeed(0, 0.15);
    MOTOR_SetSpeed(1, 0.15);

    while (distanceG < 550 && distanceD < 550)
    {
        distanceG = ROBUS_ReadIR(0);
        distanceD = ROBUS_ReadIR(1) * 2;
        Serial.print("gauche : ");
        Serial.print(distanceG);
        Serial.print("droite : ");
        Serial.print(distanceD);
        Serial.print("\n");
        if (distanceG < distanceD)
        {
            /*MOTOR_SetSpeed(1, 0.30);
            MOTOR_SetSpeed(0, 0.15);*/
            tourner(3, 0);
        }
        else
        {
            /*MOTOR_SetSpeed(1, 0.15);
            MOTOR_SetSpeed(0, 0.30);*/
            tourner(3, 1);
        }
        avancer(3, 0.15);
    }
    
    MOTOR_SetSpeed(0, 0);
    MOTOR_SetSpeed(1, 0);

    // monter le lift
    SERVO_SetAngle(0, ANGLE_ELEVATION);
    delay(1000);
}

void deposerBallon()
{
    SERVO_SetAngle(0, ANGLE_SOL);
}

float placerBallonDroit()
{
    float distanceBallon = 0;

    ENCODER_Reset(0);
    ENCODER_Reset(1);

    float distanceG = ROBUS_ReadIR(0), distanceD = ROBUS_ReadIR(1)*2;

    if (distanceG > distanceD)
    {
        MOTOR_SetSpeed(0, -0.15);
        MOTOR_SetSpeed(1, 0.15);
    }
    else
    {
        MOTOR_SetSpeed(0, 0.15);
        MOTOR_SetSpeed(1, -0.15);
    }



    while(distanceG < 350 && distanceD < 350)
    {
        distanceG = ROBUS_ReadIR(0);
        Serial.print(distanceG);
        Serial.print(" ");
        distanceD = ROBUS_ReadIR(1)*2;
        Serial.print(distanceD);
        Serial.print("\n");
        delay(100);
    }

    MOTOR_SetSpeed(0, 0);
    MOTOR_SetSpeed(1, 0);

    distanceBallon = sqrt(valeursensor(0)*valeursensor(0) - DISTANCE_CENTRE_IR*DISTANCE_CENTRE_IR);

    return distanceBallon;
}