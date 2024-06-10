#include "Car.hpp"

namespace {
	const double DELTA_TIME_STANDARD = 0.0005;

	const double MAX_SPEED = 20;
	const double MIN_SPEED = -18;

	//speed acceleration
	const double FORWARD_ACC = 0.05;
	const double BACKWARD_DEC = 0.032;
	const double SLOW_DOWN_DEC = 0.008;

	const double MAX_WHEEL_ROT = 0.12;
	const double ANGULAR_ACC = 0.003;
	const double STRAIGHTENING_SPEED = 0.002;

} // unnamed namespace


void Car::driveForward() {
	if (speed < MAX_SPEED) {
		speed += FORWARD_ACC;

		if (speed < 0) {
			speed += SLOW_DOWN_DEC;
		}
	}
}

void Car::driveBackward() {
	if (speed > MIN_SPEED) {
		speed -= BACKWARD_DEC;

		if (speed > 0) {
			speed -= SLOW_DOWN_DEC;
		}
	}
}

void Car::speedDown() {;
	if (speed > SLOW_DOWN_DEC) {
		speed -= SLOW_DOWN_DEC;
	}
	else if (speed < -SLOW_DOWN_DEC) {
		speed += SLOW_DOWN_DEC;
	}
	else {
		speed = 0;
	}
}

double Car::getSpeed() const {
	return speed;
}

void Car::wheelsRight()
{
	if (dir.y >= 0) {
		dir.x += wheelsRotation * 0.008;
	}
	else {
		dir.x -= wheelsRotation * 0.008;
	}

	if (dir.x >= 0) {
		dir.y -= wheelsRotation * 0.008;
	}
	else {
		dir.y += wheelsRotation * 0.008;
	}
}

void Car::wheelsLeft()
{
	if (dir.y >= 0) {
		dir.x -= abs(wheelsRotation) * 0.008;
	}
	else {
		dir.x += abs(wheelsRotation) * 0.008;
	}

	if (dir.x >= 0) {
		dir.y += abs(wheelsRotation) * 0.008;
	}
	else {
		dir.y -= abs(wheelsRotation) * 0.008;
	}
}

void Car::rotateRight() {
	if (wheelsRotation < MAX_WHEEL_ROT) {
		wheelsRotation += ANGULAR_ACC;

		if (wheelsRotation < 0) {
			wheelsRotation += STRAIGHTENING_SPEED;
		}
	}

	if (speed > 0) {
		wheelsRight();
	}
	else if (speed < 0) {
		wheelsLeft();
	}
}

void Car::rotateLeft() {
	if (wheelsRotation > -MAX_WHEEL_ROT) {
		wheelsRotation -= ANGULAR_ACC;

		if (wheelsRotation > 0) {
			wheelsRotation -= STRAIGHTENING_SPEED;
		}
	}

	if (speed > 0) {
		wheelsLeft();
	}
	else if (speed < 0) {
		wheelsRight();
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

Position Car::getDirection() const {
	return dir;
}

void Car::setDirection(Position dir) {
	this -> dir = dir;
}

Position Car::getPosition() const {
	return pos;
}

void Car::moveCar() {
	pos.x += 2 * speed * dir.x * DELTA_TIME_STANDARD;
	pos.y -= speed * dir.y * DELTA_TIME_STANDARD;
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