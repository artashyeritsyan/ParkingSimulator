#include "Car.h"

double Car::driveForward() {
	if (speed < MAX_SPEED) {
		speed += FORWARD_ACC;
	}
}

double Car::driveBackward() {
	if (speed > MIN_SPEED) {
		speed += BACKWARD_ACC;
	}
}

double Car::speedDown() {;
	if (speed > DEFAULT_DECC) {
		speed -= DEFAULT_DECC;
	}
	else if (speed < -DEFAULT_DECC) {
		speed += DEFAULT_DECC;
	}
	else {
		speed = 0;
	}
}

double Car::getSpeed() {

}
void Car::rotateLeft() {

}
void Car::rotateRight() {

}
void Car::straightening() {

}
double Car::getRotation() {

}
double Car::getDirection() {

}