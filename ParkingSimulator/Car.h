#pragma once
#include <iostream>

const double MAX_SPEED = 10;
const double MIN_SPEED = 6;
//speed acceleration
const double FORWARD_ACC = 0.5;
const double BACKWARD_ACC = -0.4;
const double SLOW_DOWN_DECC = 0.2;

const double ANGULAR_ACC = 0.05;
const double STRAIGHTING_SPEED = 0.02;

class Car
{
public:
	double driveForward();
	double driveBackward();
	double speedDown();
	double getSpeed() const;
	void rotateRight();
	void rotateLeft();
	void straightening();
	double getRotation() const;
	double getDirection() const;
	void setDirection(int dir);

private:
	double speed = 0;
	double rotation = 0;
	int direction = 0;

};

