#pragma once

#define COEFF_DIST 0.98
#define DR_R 17.6
#define COEFF_ANGLE 1
#define ROUGE 0
#define VERT 1
#define BLEU 2 
#define JAUNE 3

float PID();

void avancer(float distance, float vitesse);

void reculer(float distance, float vitesse);

void allerscacher(int couleur);

int avancerVerifierBalle(float distanceMax, float vitesse);

void tourner(float angleDegree, int direction);