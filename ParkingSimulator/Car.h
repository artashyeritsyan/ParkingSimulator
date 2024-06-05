#pragma once
#include <iostream>

const double MAX_SPEED = 10;
const double MIN_SPEED = 6;
//speed acceleration
const double FORWARD_ACC = 0.5;
const double BACKWARD_ACC = -0.4;
const double DEFAULT_DECC = 0.2;

class Car
{
public:
	double driveForward();
	double driveBackward();
	double speedDown();
	double getSpeed();
	void rotateLeft();
	void rotateRight();
	void straightening();
	double getRotation();
	double getDirection();
	void setDirection();

private:
	double speed = 0;
	double rotation = 0;
	int direction = 0;

};

