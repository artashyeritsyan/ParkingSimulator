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
	if (speed > SLOW_DOWN_DECC) {
		speed -= SLOW_DOWN_DECC;
	}
	else if (speed < -SLOW_DOWN_DECC) {
		speed += SLOW_DOWN_DECC;
	}
	else {
		speed = 0;
	}
}

double Car::getSpeed() const {
	return speed;
}

void Car::rotateRight() {
	rotation += ANGULAR_ACC;
}

void Car::rotateLeft() {
	rotation -= ANGULAR_ACC;
}

void Car::straightening() {
	if (rotation > STRAIGHTING_SPEED) {
		rotation -= STRAIGHTING_SPEED;
	}
	else if (rotation < -STRAIGHTING_SPEED) {
		rotation += STRAIGHTING_SPEED;
	}
	else {
		rotation = 0;
	}
}

double Car::getRotation() const {
	return rotation;
}

double Car::getDirection() const {
	return direction;
}

void Car::setDirection(int dir) {
	direction = dir;
}