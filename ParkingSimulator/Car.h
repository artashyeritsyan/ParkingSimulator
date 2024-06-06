#pragma once
#include <iostream>
#include <cmath>

const double MAX_SPEED = 15;
const double MIN_SPEED = -10;
//speed acceleration
const double FORWARD_ACC = 1;
const double BACKWARD_DEC = 0.8;
const double SLOW_DOWN_DECC = 0.6;

const double MAX_WHEEL_ROT = 0.1;
const double ANGULAR_ACC = 0.01;
const double STRAIGHTENING_SPEED = 0.01;

struct Position {
	double x, y;
};

struct Direction {
	double x, y;
};
class Car
{
public:
	void driveForward();
	void driveBackward();
	void speedDown();
	double getSpeed() const;
	void rotateRight();
	void rotateLeft();
	void normalizeRotation();
	double getRotation() const;
	Direction getDirection() const;
	void setDirection(Direction dir);
	Position getPosition() const;

	void moveCar();

	//std::pair<double, double> rotate_point(double x, double y, double k);

private:
	double speed = 0;
	double rotation = 0;
	double wheelsRotation = 0;
	Position pos = { 20, 20 };
	Direction dir = { 1, 0 };

};

