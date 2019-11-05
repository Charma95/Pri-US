#pragma once 

#include <ColorSensor.h>

/* Typedef */
typedef struct 
{
    int kelvin;
    char average;
    char lux;
}COLOR_T;



/* Functions declaration*/
bool colorSensorInit(void);
void setTime(tcs34725IntegrationTime_t intTime);
void setGain(tcs34725Gain_t gain);
void getColorData(uint16_t *r, uint16_t *g, uint16_t *b, uint16_t *c);
uint16_t colorTemperature(uint16_t r, uint16_t g, uint16_t b);
uint16_t luxCalc(uint16_t r, uint16_t g, uint16_t b);
void writeByte (uint8_t reg, uint32_t value);
uint8_t readByte (uint8_t reg);
uint16_t readInteger (uint8_t reg);
void attachInterrupt(boolean flag);
void detachInterrupt(void);
void setLimits(uint16_t l, uint16_t h);
void enable(void);


extern COLOR_T color_t;