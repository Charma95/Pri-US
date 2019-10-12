#include <ServoControl.h>
#include <Arduino.h>

/* @ Author: Charles Lévesque-Matte
 * @ Param : -uint8_t distance: Distance we want the rover to make in cm
 *           -uint8_t speed : The speed we want the rover to go. Value between -1.0 to 1.0
 * @ Function call : Error = straightLine(45, 0.5);
 * @ Return : ERROR_T pidError : 
 *                              - NONE : No errors
 *                              - INVALID_SPEED : The speed must be a floating point and between -1.0 and 1.0
 *                              - INVALID_LENGTH: The distance must be an integer
 */
ERROR_T straightLine(uint8_t distance,float speed)
{
    ERROR_T pidError = NONE;
    int32_t enc0Value = 0, enc1Value = 0, errorFactor = 0;
    float integralFactor = 0, Kp = 0.00000005, Ki = 0.000025, length = 0;

    enc0Value = ENCODER_ReadReset(0);       /* Left encoder */
    enc1Value = ENCODER_ReadReset(1);       /* Right encoder */

      /* Each wheel have a diameter of 7.62 cm * pi = 23.94 cm of circumference
       there is 3200 pulse per rotation of a wheel hence 3200/23.94cm = 133.67 
       pulse per cm
     */
    length = distance * oneCmClick;      /* Convert to pulse count */

   if((speed < -1.0) || (speed > 1.0))
   {
       pidError = INVALID_SPEED;
   }
   else
   {
    while(enc1Value <= length)           /* Master encoder*/
     {                                   
        MOTOR_SetSpeed(0, speed);        /* Left(Master) motor is set to forward half max speed */
        enc0Value = ENCODER_Read(0);
        enc1Value = ENCODER_Read(1);
        errorFactor = enc1Value - enc0Value;      /* determines the error factor */
        integralFactor += (0.080 * errorFactor);
        MOTOR_SetSpeed(1, speed + Kp * errorFactor + Ki * integralFactor);  /* Set slave speed */
        delay(80);
        
        /*Ancienne valeur de dt = 0.083*/
     }  
   }
    return pidError;
}

/* @ Author: Charles Lévesque-Matte
 * @ Param : -uint8_t distance: Distance we wnat the rover to make in cm
 *           -uint8_t speed : The speed we want the rover to go. Value between -1.0 to 1.0
 * @ Function call : Error = straightLine(45, 0.5);
 * @ Return : ERROR_T turnError : 
 *                              - NONE : No errors
 *                              - INVALID_ANGLE : The speed must be between 0 and 360                            
 */
ERROR_T turn(char direction, uint8_t angle)
{
    ERROR_T turnError = NONE;
    uint16_t clickCount = 0;
    uint16_t angleClick = 0;
    stop();
    
    angleClick = angleToClick(angle);
   
    ENCODER_Reset(0);
    ENCODER_Reset(1);

    if(direction == 'L')   /* Left */
    {
      while(clickCount <= angleClick)
      {
       MOTOR_SetSpeed(1, 0.4);
       clickCount = ENCODER_Read(1);
       /* Debug only */
      // Serial.println(clickCount);
      }

    }
    else          /* Right */
    {
         while(clickCount != angleClick)
      {
       MOTOR_SetSpeed(0, 0.4);
       clickCount = ENCODER_Read(0);
      }
    }
    stop();
    return turnError;
}

/* @ Author: Charles Lévesque-Matte
 * @ Param : -uint8_t distance: Distance we wnat the rover to make in cm
 *           -uint8_t speed : The speed we want the rover to go. Value between -1.0 to 1.0
 * @ Function call : Error = straightLine(45, 0.5);
 * @ Return : ERROR_T pidError : 
 *                              - NONE : No errors
 *                              - INVALID_SPEED : The speed must be a floating point and between -1.0 and 1.0
 *                              - INVALID_LENGTH: The distance must be an integer
 */
void stop(void)
{    
 MOTOR_SetSpeed(0, 0.0);
 MOTOR_SetSpeed(1, 0.0);   
}

/* @ Author: Charles Lévesque-Matte
 * @ Param : -uint8_t distance: Distance we wnat the rover to make in cm
 *           -uint8_t speed : The speed we want the rover to go. Value between -1.0 to 1.0
 * @ Function call : Error = straightLine(45, 0.5);
 * @ Return : ERROR_T pidError : 
 *                              - NONE : No errors
 *                              - INVALID_SPEED : The speed must be a floating point and between -1.0 and 1.0
 *                              - INVALID_LENGTH: The distance must be an integer
 */
uint16_t angleToClick(uint8_t angle)
{
  float arcLength = ((2 * 3.141592653589793 * 18.4) * (float(angle)/360.0));
  return((uint16_t)(arcLength * oneCmClick));
}

ERROR_T halfRoundTrip()
{
  ERROR_T Error = NONE;
  Error = straightLine(110, 0.3 );
  Error = turn('L', 85);
  robotReset();
  Error = straightLine(42, 0.3);
  robotReset();
  Error = straightLine(45, 0.3);
  Error = turn('R', 92);
  robotReset();
  Error = straightLine(20, 0.3);
  Error = turn('R', 87);
  robotReset();
  Error = straightLine(37, 0.3);
  Error = turn('L', 95);
  robotReset();
  Error = straightLine(45, 0.3);
  robotReset();
  Error = straightLine(50, 0.3);
  robotReset();
  Error = straightLine(50, 0.3);
  robotReset();
  Error = straightLine(40, 0.3);
  Error = turn('R', 95);
  robotReset();
  Error = straightLine(20, 0.3);
  Error = turn('L', 88);
  robotReset();
  Error = straightLine(110, 0.3);
  stop();
  delay(1000);// Delais pour décharger le CPU
  stop();

  return Error;
}

ERROR_T winningDance()
{
  ERROR_T errorWin = NONE;
  errorWin = turn('L', 90);
  errorWin = turn('L', 90);
  errorWin = turn('L', 90);
  errorWin = turn('L', 90);
  stop();
  errorWin = turn('R', 90);
  errorWin = turn('R', 90);
  errorWin = turn('R', 90);
  errorWin = turn('R', 90);
  stop();
 return errorWin;
}

ERROR_T uTurn()
{
  ERROR_T errorTurn = NONE;
  uint16_t clickTurn = 0;
  while(clickTurn < angleToClick(93))
  {
  MOTOR_SetSpeed(0, 0.3);
  MOTOR_SetSpeed(1, -0.3);
  clickTurn = ENCODER_Read(0);
  /* Debug purpose only */
  //Serial.println(clickTurn);
  }
  stop();
  robotReset();
  return errorTurn;
}

  void robotReset()
  {
    ENCODER_Reset(0);
    ENCODER_Reset(1); 
  }