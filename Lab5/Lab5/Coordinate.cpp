#include "Coordinate.h"
#include <iostream>
#include <cmath>
using namespace std;

Coordinate::Coordinate(float X, float Y, float Z) {
	x = X;
	y = Y;
	z = Z;
}

Coordinate::~Coordinate() {

}

float Coordinate::length() {
	float length = (float)sqrt(x*x + y * y + z * z);
	return length;
}

void Coordinate::getCoordinate() {
	cout << " Coordinate: (" << x << ", " << y << ", " << z << ")";
}

Coordinate Coordinate::singleVector() {
	float len = length();
	Coordinate singleV(x / len, y / len, z / len);
	return singleV;
}

Coordinate Coordinate::operator+(Coordinate second) {
	Coordinate sum(this->x + second.x, this->y + second.y, this->z + second.z);
	return sum;
}

Coordinate Coordinate::operator-(Coordinate second) {
	Coordinate diff(this->x - second.x, this->y - second.y, this->z - second.z);
	return diff;
}

Coordinate Coordinate::operator*(float num) {
	Coordinate mult(this->x * num, this->y * num, this->z * num);
	return mult;
}

bool Coordinate::operator==(Coordinate second) {
	if (this->x == second.x && this->y == second.y && this->z == second.z)
		return true;
	else
		return false;
}

float Coordinate::distance(Coordinate second) {
	Coordinate diff = second - *this;
	float len = diff.length();
	return len;
}