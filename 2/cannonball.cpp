#include <iostream>
#include <unistd.h>
#include <math.h>
#include <cstdlib>
#include <stdlib.h>
#include "cannonball.h"
using namespace std;



double acclY() {
	return 9.81;
}

double acclX() {
	return 0;
}

double velY(double startVel, double time) {
	return startVel - acclY() * time;
}

double velX(double startVel, double time) {
	return startVel + acclX() * time;
}

double velIntY(double startVel, double time) {
	double vel = startVel;
	int step = 100;
	for (int i=0; i<(time/step); i++) {
		vel += acclY()*step;
	}
	return vel;
}

double posXFormula(double startVel, double time) {
	return 0 + velX(startVel, time) * time + 0.5 * acclX() * time * time;
}

double posYFormula(double startVel, double time) {
	return 0 + velY(startVel, time) * time + 0.5 * acclY() * time * time;
}

double posXInt(double startVel, double time) {
	double pos = 0;
	int step = 100;
	for (int i=0; i<(time/step); i++) {
		pos += velX(startVel, time)*step;
	}
	return pos;
}

double posYInt(double startVel, double time) {
	double pos = 0;
	int step = 1000;
	for (int i=0; i<(time/step); i++) {
		pos += velY(startVel, time)*step;
	}
	return pos;
}

void printTime(double secs) {
	int hour = secs/(60*60);
	secs -= hour * 60 * 60;
	int min = (secs/60);
	secs -= hour * 60;
	double sec = secs;
	cout << hour << " timer, " << min << " min, " << sec << " sek";
}

void printPicture(double velocityX, double velocityY, double time, int distance, double top, double target) {
	int screenHeight = 25;
	int screenWidth = 80;
	int xScale = 100;
	int yScale = 100;
	int posY = posYFormula(velocityY, time)/(yScale/screenHeight);
	int posX = posXFormula(velocityX, time)/(xScale/(screenWidth));

	cout << string( 10, '\n' );
	for (int y=0; y<screenHeight; y++) {
		for (int x=0; x<screenWidth; x++) {
			if (posX == x && (posY == screenHeight-y || (posY == 0 && y == screenHeight-1))) {
				cout << "o";
			}
			else if (y == screenHeight-1 && x==70) {
				cout << "+";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
	for (int i=0; i<= screenWidth+1; i++) cout << "-";
	cout << endl;
	cout << "| Hastighet X: " << velocityX << "\t Hastighet Y: " << velY(velocityY, time) <<endl;
	cout << "| Høyde: " << posYFormula(velocityY, time) << "    \t Distanse: " << posXFormula(velocityX, time) << "\t";
	printTime(time);
	cout << endl;
	for (int i=0; i<= screenWidth+1; i++) cout << "-";
	cout << endl;
}

double flightTime(double startVel) {
	double time = 0.1;
	while (posYFormula(startVel, time) > 0) {
		time += 0.1;
	}
	return time;
}

void getUserInput(double *theta, double *absVelocity) {
	cout << "Skriv inn vinkel i grader (0 - 90): ";
	cin >> *theta;
	*theta = *theta * 3.14 / 180;
	cout << "Skriv inn absolutt hastighet: ";
	cin >> *absVelocity;
}

double getVelocityX(double theta, double absVelocity) {
	return absVelocity * cos(theta);
}

double getVelocityY(double theta, double absVelocity) {
	return absVelocity * sin(theta);
}

void getVelocityVector(double theta, double absVelocity, 
	double *velocityX, double *velocityY) {
	*velocityX = getVelocityX(theta, absVelocity);
	*velocityY = getVelocityY(theta, absVelocity);
}

double getDistanceTraveled(double velocityX, double velocityY) {
	return posXFormula(velocityX, flightTime(velocityY));
}

void simLoop(double velocityX, double velocityY, int speed, double target=-1) {
	double flight = flightTime(velocityY);
	double distance = getDistanceTraveled(velocityX, velocityY);
	double height = posYFormula(velocityY, flight/2);
	for (double t=0.1; t<flight; t+=0.1) {
		printPicture(velocityX, velocityY, t, distance, height, target);
		usleep(speed);
	}
}

void simulate() {
	double theta = 0.0;
	double absVelocity = 0.0;
	double velocityX = 0.0;
	double velocityY = 0.0;

	getUserInput(&theta, &absVelocity);
	getVelocityVector(theta, absVelocity, &velocityX, &velocityY);

	simLoop(velocityX, velocityY, 100000);
	
	cout << endl;
	cout << "Vinkel:\t\t" << theta << " grader" << endl;
	cout << "Abs.Hastighet:\t" << absVelocity << " m/s" << endl;
	cout << "Hastighet X:\t" << velocityX << " m/s" << endl;
	cout << "Hastighet Y:\t" << velocityY << " m/s" << endl;
	cout << "Flytid:\t\t" << flightTime(velocityY) << " s" << endl;
	cout << "Distanse:\t" << getDistanceTraveled(velocityX, velocityY) << " meter" << endl;
	cout << "Maks høyde:\t" << posYFormula(velocityY, flightTime(velocityY)/2) << " meter" << endl << endl;
}

double optimalAngleForMaxDistance(double absVelocity) {
	double velX = 0.0;
	double velY = 0.0;
	double max = 0.0;
	double dist = 0.0;
	double bestAngle = 0.0;

	for (double a=0.0; a<=90; a+=1.0) {
		getVelocityVector(a* 3.14 / 180, absVelocity, &velX, &velY);
		dist = getDistanceTraveled(velX, velY);
		if (dist > max) {
			max = dist;
			bestAngle = a;
		}
		//if ((int)a%5 == 0) simLoop(velX, velY, 10000);
		//cout << "Vinkel: " << a << "\t distanse: " << dist << endl;
	}
	cout << endl << "Beste vinkel er " << bestAngle << endl << endl;
	return bestAngle;
}

double targetPractice(double distanceToTarget, 
	double velocityX, double velocityY) {
	return distanceToTarget - getDistanceTraveled(velocityX, velocityY);
}

void playTargetPractice() {
	double theta = 0.0;
	double absVelocity = 0.0;
	double velocityX = 0.0;
	double velocityY = 0.0;
	int distanceToTarget = (rand() % 70) + 30;
	double diff = 0.0;
	cout << "Du skal nå prøve å treffe en blink som er " << distanceToTarget << " meter unna." << endl;
	cout << "Du får 10 forsøk." << endl;

	for (int i=0; i<10; i++) {
		getUserInput(&theta, &absVelocity);
		getVelocityVector(theta, absVelocity, &velocityX, &velocityY);
		simLoop(velocityX, velocityY, 100000);
		diff = targetPractice(distanceToTarget, velocityX, velocityY);
		if(abs((int)diff) <= 1) {
			cout << endl << "Du traff bare "<< diff <<" meter unna! Vi sier det er greit :D" << endl << endl;
			break;
		}
		if (diff < 0) {
			cout << "Du skjøt "<< abs((int)diff) << " meter for langt" << endl;
		}
		else {
			cout << "Du skjøt "<< diff << " meter for kort" << endl;
			
		}
		cout << "Prøv på nytt. Du har " << 10-i-1 << " forsøk igjen" << endl;
	}
}