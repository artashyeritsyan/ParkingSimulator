#pragma once
#include <iostream>
#include <cmath>

struct Position {
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
	Position getDirection() const;
	void setDirection(Position dir);
	Position getPosition() const;

	void moveCar();

	//std::pair<double, double> rotate_point(double x, double y, double k);

private:
	void wheelsRight();
	void wheelsLeft();

private:
	double speed = 0;
	double rotation = 0;
	double wheelsRotation = 0;
	Position pos = { 10, 10 };
	Position dir = { 1, 0 };

};

