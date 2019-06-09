#include "Coordinate.h"

class Triangle {
public:
	Coordinate A;
	Coordinate B;
	Coordinate C;
	Coordinate center;

	Triangle(Coordinate, Coordinate, Coordinate);
	~Triangle();

};
