#pragma once

#define ANGLE_ELEVATION 5
#define ANGLE_SOL 22
#define ANGLE_OUVERT 180
#define ANGLE_OUVERTB 90
#define ANGLE_FERME 135
#define ANGLE_FERMEB 45
#define DISTANCE_CENTRE_IR 5
#define ROBOT_A 0
#define ROBOT_B 1

void trouverBallon(void);

int souleverBallon(float distance);

void deposerBallon(void);

float placerBallonDroit(void);

int attraperBallon(int robot);

void lacherBallon(int robot);

