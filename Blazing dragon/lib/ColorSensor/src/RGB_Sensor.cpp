#include <RGB_Sensor.h>
#include <ColorSensor.h>

/* Object creation */
 Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

/* @ Author: Charles Lévesque-Matte
 * @ Param : -uint8_t distance: Distance we want the rover to make in cm
 *           -uint8_t speed : The speed we want the rover to go. Value between -1.0 to 1.0
 * @ Function call : Error = straightLine(45, 0.5);
 * @ Return : ERROR_T pidError : 
 *                              - NONE : No errors
 *                              - INVALID_SPEED : The speed must be a floating point and between -1.0 and 1.0
 *                              - INVALID_LENGTH: The distance must be an integer
 */
bool colorSensorInit(void)
{
    bool ret = tcs.begin();
    return ret;
}
/* @ Author: Charles Lévesque-Matte
 * @ Param : -uint8_t distance: Distance we want the rover to make in cm
 *           -uint8_t speed : The speed we want the rover to go. Value between -1.0 to 1.0
 * @ Function call : Error = straightLine(45, 0.5);
 * @ Return : ERROR_T pidError : 
 *                              - NONE : No errors
 *                              - INVALID_SPEED : The speed must be a floating point and between -1.0 and 1.0
 *                              - INVALID_LENGTH: The distance must be an integer
 */
void setTime(tcs34725IntegrationTime_t intTime)
{
    tcs.setIntegrationTime( intTime);
}
/* @ Author: Charles Lévesque-Matte
 * @ Param : -uint8_t distance: Distance we want the rover to make in cm
 *           -uint8_t speed : The speed we want the rover to go. Value between -1.0 to 1.0
 * @ Function call : Error = straightLine(45, 0.5);
 * @ Return : ERROR_T pidError : 
 *                              - NONE : No errors
 *                              - INVALID_SPEED : The speed must be a floating point and between -1.0 and 1.0
 *                              - INVALID_LENGTH: The distance must be an integer
 */
void setGain(tcs34725Gain_t gain)
{
    tcs.setGain(gain);
}
/* @ Author: Charles Lévesque-Matte
 * @ Param : -uint8_t distance: Distance we want the rover to make in cm
 *           -uint8_t speed : The speed we want the rover to go. Value between -1.0 to 1.0
 * @ Function call : Error = straightLine(45, 0.5);
 * @ Return : ERROR_T pidError : 
 *                              - NONE : No errors
 *                              - INVALID_SPEED : The speed must be a floating point and between -1.0 and 1.0
 *                              - INVALID_LENGTH: The distance must be an integer
 */
void getColorData(uint16_t *r, uint16_t *g, uint16_t *b, uint16_t *c)
{
    tcs.getRawData(r, g, b, c);
}
/* @ Author: Charles Lévesque-Matte
 * @ Param : -uint8_t distance: Distance we want the rover to make in cm
 *           -uint8_t speed : The speed we want the rover to go. Value between -1.0 to 1.0
 * @ Function call : Error = straightLine(45, 0.5);
 * @ Return : ERROR_T pidError : 
 *                              - NONE : No errors
 *                              - INVALID_SPEED : The speed must be a floating point and between -1.0 and 1.0
 *                              - INVALID_LENGTH: The distance must be an integer
 */
uint16_t colorTemperature(uint16_t r, uint16_t g, uint16_t b)
{
    uint16_t ret = tcs.calculateColorTemperature(r, g, b);
    return ret;
}
/* @ Author: Charles Lévesque-Matte
 * @ Param : -uint8_t distance: Distance we want the rover to make in cm
 *           -uint8_t speed : The speed we want the rover to go. Value between -1.0 to 1.0
 * @ Function call : Error = straightLine(45, 0.5);
 * @ Return : ERROR_T pidError : 
 *                              - NONE : No errors
 *                              - INVALID_SPEED : The speed must be a floating point and between -1.0 and 1.0
 *                              - INVALID_LENGTH: The distance must be an integer
 */
uint16_t luxCalc(uint16_t r, uint16_t g, uint16_t b)
{
    uint16_t ret = tcs.calculateLux(r, g, b);
    return ret;
}
/* @ Author: Charles Lévesque-Matte
 * @ Param : -uint8_t distance: Distance we want the rover to make in cm
 *           -uint8_t speed : The speed we want the rover to go. Value between -1.0 to 1.0
 * @ Function call : Error = straightLine(45, 0.5);
 * @ Return : ERROR_T pidError : 
 *                              - NONE : No errors
 *                              - INVALID_SPEED : The speed must be a floating point and between -1.0 and 1.0
 *                              - INVALID_LENGTH: The distance must be an integer
 */
void writeByte (uint8_t reg, uint32_t value)
{
    tcs.write8(reg, value);
}
/* @ Author: Charles Lévesque-Matte
 * @ Param : -uint8_t distance: Distance we want the rover to make in cm
 *           -uint8_t speed : The speed we want the rover to go. Value between -1.0 to 1.0
 * @ Function call : Error = straightLine(45, 0.5);
 * @ Return : ERROR_T pidError : 
 *                              - NONE : No errors
 *                              - INVALID_SPEED : The speed must be a floating point and between -1.0 and 1.0
 *                              - INVALID_LENGTH: The distance must be an integer
 */
uint8_t readByte (uint8_t reg)
{
    uint8_t ret = tcs.read8(reg);
    return ret;
}
/* @ Author: Charles Lévesque-Matte
 * @ Param : -uint8_t distance: Distance we want the rover to make in cm
 *           -uint8_t speed : The speed we want the rover to go. Value between -1.0 to 1.0
 * @ Function call : Error = straightLine(45, 0.5);
 * @ Return : ERROR_T pidError : 
 *                              - NONE : No errors
 *                              - INVALID_SPEED : The speed must be a floating point and between -1.0 and 1.0
 *                              - INVALID_LENGTH: The distance must be an integer
 */
uint16_t readInteger (uint8_t reg)
{   
    uint16_t ret = tcs.read16(reg);
    return ret;
}
/* @ Author: Charles Lévesque-Matte
 * @ Param : -uint8_t distance: Distance we want the rover to make in cm
 *           -uint8_t speed : The speed we want the rover to go. Value between -1.0 to 1.0
 * @ Function call : Error = straightLine(45, 0.5);
 * @ Return : ERROR_T pidError : 
 *                              - NONE : No errors
 *                              - INVALID_SPEED : The speed must be a floating point and between -1.0 and 1.0
 *                              - INVALID_LENGTH: The distance must be an integer
 */
void attachInterrupt(boolean flag)
{
    tcs.setInterrupt(flag);
}
/* @ Author: Charles Lévesque-Matte
 * @ Param : -uint8_t distance: Distance we want the rover to make in cm
 *           -uint8_t speed : The speed we want the rover to go. Value between -1.0 to 1.0
 * @ Function call : Error = straightLine(45, 0.5);
 * @ Return : ERROR_T pidError : 
 *                              - NONE : No errors
 *                              - INVALID_SPEED : The speed must be a floating point and between -1.0 and 1.0
 *                              - INVALID_LENGTH: The distance must be an integer
 */
void detachInterrupt(void)
{
    tcs.clearInterrupt();
}
/* @ Author: Charles Lévesque-Matte
 * @ Param : -uint8_t distance: Distance we want the rover to make in cm
 *           -uint8_t speed : The speed we want the rover to go. Value between -1.0 to 1.0
 * @ Function call : Error = straightLine(45, 0.5);
 * @ Return : ERROR_T pidError : 
 *                              - NONE : No errors
 *                              - INVALID_SPEED : The speed must be a floating point and between -1.0 and 1.0
 *                              - INVALID_LENGTH: The distance must be an integer
 */
void setLimits(uint16_t l, uint16_t h)
{
    tcs.setIntLimits(l, h);
}


/* @ Author: Charles Lévesque-Matte
 * @ Param : -uint8_t distance: Distance we want the rover to make in cm
 *           -uint8_t speed : The speed we want the rover to go. Value between -1.0 to 1.0
 * @ Function call : Error = straightLine(45, 0.5);
 * @ Return : ERROR_T pidError : 
 *                              - NONE : No errors
 *                              - INVALID_SPEED : The speed must be a floating point and between -1.0 and 1.0
 *                              - INVALID_LENGTH: The distance must be an integer
 */
void enable(void)
{
    tcs.enable();
}

