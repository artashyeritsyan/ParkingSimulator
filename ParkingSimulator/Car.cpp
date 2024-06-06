#include "Car.h"

void Car::driveForward() {
	if (speed < MAX_SPEED) {
		speed += FORWARD_ACC;

		if (speed < 0) {
			speed += SLOW_DOWN_DECC;
		}
	}
}

void Car::driveBackward() {
	if (speed > MIN_SPEED) {
		speed -= BACKWARD_DEC;

		if (speed > 0) {
			speed -= SLOW_DOWN_DECC;
		}
	}
}

void Car::speedDown() {;
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
	if (wheelsRotation < MAX_WHEEL_ROT) {
		wheelsRotation += ANGULAR_ACC;
	}

	if (speed != 0) {
		if (dir.y <= 0) {
			dir.x += wheelsRotation;
		}
		else {
			dir.x -= wheelsRotation;
		}

		if (dir.x <= 0) {
			dir.y -= wheelsRotation;
		}
		else {
			dir.y += wheelsRotation;
		}
	}
}

void Car::rotateLeft() {
	if (wheelsRotation > -MAX_WHEEL_ROT) {
		wheelsRotation -= ANGULAR_ACC;
	}

	if (speed != 0) {
		if (dir.y >= 0) {
			dir.x -= wheelsRotation;
		}
		else {
			dir.x += wheelsRotation;
		}

		if (dir.x >= 0) {
			dir.y += wheelsRotation;
		}
		else {
			dir.y -= wheelsRotation;
		}
	}
}

void Car::normalizeRotation() {
	if (wheelsRotation > STRAIGHTENING_SPEED) {
		wheelsRotation -= STRAIGHTENING_SPEED;
	}
	else if (wheelsRotation < -STRAIGHTENING_SPEED) {
		wheelsRotation += STRAIGHTENING_SPEED;
	}
	else {
		wheelsRotation = 0;
	}
}

double Car::getRotation() const {
	return wheelsRotation;
}

Direction Car::getDirection() const {
	return dir;
}

void Car::setDirection(Direction dir) {
	this -> dir = dir;
}

Position Car::getPosition() const {
	return pos;
}

void Car::moveCar() {
	pos.x += speed * dir.x * 0.1;
	pos.y += speed * dir.y * 0.1;
}

//std::pair<double, double> Car::rotate_point(double x, double y, double k) {
//	// Calculate the angle in radians
//	double theta = k * (M_PI);  // 90 degrees in radians is pi/2
//
//	// Calculate the rotated coordinates
//	double x_new = x * cos(theta) - y * sin(theta);
//	double y_new = x * sin(theta) + y * cos(theta);
//
//	return std::make_pair(x_new, y_new);
//}