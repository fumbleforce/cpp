#pragma once

double acclY();

double velY(double startVel, double time);

double velIntY(double startVel, double time);

double posXFormula(double startVel, double time);

double posYFormula(double startVel, double time);

double posXInt(double startVel, double time);

double PosYInt(double startVel, double time);

void printTime(int secs);

double flightTime(double startVel);

void getUserInput(double *theta, double *absVelocity);

double getVelocityX(double theta, double absVelocity);

double getVelocityY(double theta,double absVelocity);

void getVelocityVector(double theta, double absVelocity, 
	double *velocityX, double *velocityY);

double getDistanceTraveled(double velocityX, double velocityY);

double optimalAngleForMaxDistance(double absVelocity);

double targetPractice(double distanceToTarget, 
	double velocityX, double velocityY);

void playTargetPractice();