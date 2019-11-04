

#include <LibRobus.h>
#include <Math.h>
#include "Lift.h"
#include "Mouvement.h"

void trouverBallon()
{
    int distanceG = 0, distanceD = 0;

    distanceG = ROBUS_ReadIR(0);
    distanceD = ROBUS_ReadIR(1);

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

        distanceG = ROBUS_ReadIR(0);
        distanceD = ROBUS_ReadIR(1);
    }
}

// la distance est en cm
void souleverBallon(float distance)
{
    // avancer jusqu'au ballon
    avancer(distance, 0.15);
    delay(500);

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

    int distanceG = ROBUS_ReadIR(0), distanceD = ROBUS_ReadIR(1);

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

    while(distanceG != distanceD)
    {
        distanceG = ROBUS_ReadIR(0);
        distanceD = ROBUS_ReadIR(1);
    }

    distanceBallon = sqrt(distanceD*distanceD - DISTANCE_CENTRE_IR*DISTANCE_CENTRE_IR);

    return distanceBallon;
}