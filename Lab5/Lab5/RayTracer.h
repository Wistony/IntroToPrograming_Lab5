#include "Triangle.h"
#include "Coordinate.h"

class RayTracer {
public:
	RayTracer();
	~RayTracer();

	void tracer();
	bool ThereIsIntersectionBetweenRayAndTriangle(Coordinate,Coordinate,Triangle);
	void DrawScreenBuffer(int,int, bool**);
};