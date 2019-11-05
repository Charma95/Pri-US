#pragma once

#define COEFF_DIST 0.98
#define DR_R 17.6
#define COEFF_ANGLE 1

float PID();

void avancer(float distance, float vitesse);

void allerscacher(float distance);

int avancerVerifierBalle(float distanceMax, float vitesse);

void tourner(float angleDegree, int direction);