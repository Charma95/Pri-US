
#include <LibRobus.h>
#include "Mouvement.h"

float PID()
{
    float correction = 0;
    static int32_t enc1_value = 0;
    static int32_t enc0_value = 0;
    int32_t integral;
    const double Kp = 0.001, Ki = 0; // const double Kp = 0.000004, Ki = 0.000000001;
    int32_t deltaT = 0.01;
    int32_t er1 = enc1_value;
    int32_t er0 = enc0_value; 
    enc0_value = ENCODER_Read(0);
    enc1_value = ENCODER_Read(1);
    int32_t e = (enc1_value-er1)-(enc0_value-er0);
    int32_t ei = enc1_value - enc0_value;
    integral = deltaT * ei;
    correction = Kp*e+Ki*integral;
    Serial.println(integral);
    
  
    return(correction);
}

void avancer(float distance, float vitesse)
{
    ENCODER_Reset(0);
    ENCODER_Reset(1);
    int32_t ei=0;
    int32_t clicMax = distance*COEFF_DIST*3200/(7.62*PI);
    float V1 = vitesse, V0 = vitesse;
    //accelerer(V1);
    while(ENCODER_Read(1)<clicMax)
    {
        MOTOR_SetSpeed(1,V1);
        MOTOR_SetSpeed(0,V0);
        float corr = PID();
        V0 = V0 + corr;
        delay(10);
    }
    MOTOR_SetSpeed(0,0.0);
    MOTOR_SetSpeed(1,0.0);
    delay(100);
}

int avancerVerifierBalle(float distanceMax, float vitesse)
{
    int balleTrouve = 0;

    ENCODER_Reset(0);
    ENCODER_Reset(1);
    int32_t ei=0;
    int32_t clicMax = distanceMax*COEFF_DIST*3200/(7.62*PI);
    float V1 = vitesse, V0 = vitesse;
    //accelerer(V1);
    while(ENCODER_Read(1)<clicMax)
    {
        if (ROBUS_ReadIR(0) < 20 || ROBUS_ReadIR(1) < 20)
        {
            MOTOR_SetSpeed(0, 0);
            MOTOR_SetSpeed(1, 0);
            return 1;
        }
        MOTOR_SetSpeed(1,V1);
        MOTOR_SetSpeed(0,V0);
        float corr = PID();
        V0 = V0 + corr;
        delay(10);
    }
    MOTOR_SetSpeed(0,0.0);
    MOTOR_SetSpeed(1,0.0);
    delay(100);

    return balleTrouve;
}

// direction : 0 = gauche, 1 = droit
void tourner(int angleDegree, int direction)
{
    ENCODER_Reset(0);
    ENCODER_Reset(1);
    int32_t moteur;
    float V0,V1;
    if(direction)
    {
        V0 = 0.2;
        V1 = -0.2;
        moteur = 0;
    }
    else 
    {
        V0 = -0.2;
        V1 = 0.2;
        moteur = 1;
    }
    float circ = PI*DR_R;
    float longueurArc = ((angleDegree*COEFF_ANGLE)/360.0)*circ; //DR_R*COEFF_360*3200/(7.62)
    int32_t clickMax = (3200/(PI*7.62))*longueurArc;
    Serial.println(angleDegree);
    
    while (ENCODER_Read(moteur)<clickMax)
    {
        MOTOR_SetSpeed(0,V0);
        MOTOR_SetSpeed(1,V1);
        
    }
    MOTOR_SetSpeed(0,0.0);
    MOTOR_SetSpeed(1,0.0);
    delay(300);
}