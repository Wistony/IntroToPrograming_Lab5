#include <iostream>
#include "Coordinate.h"
using namespace std;

int main() {

	Coordinate temp(1, 1, 1);
	Coordinate first(1, 2, 3);
	Coordinate t = temp + first;
	t.getCoordinate();
	cin.get();
}