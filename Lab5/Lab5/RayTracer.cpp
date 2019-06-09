#include <iostream>
#include "RayTracer.h"
#include <cmath>
using namespace std;

#define M_PI            3.14159265358979323846

RayTracer::RayTracer() {

}

RayTracer::~RayTracer() {

}

void RayTracer::tracer() {
	// точка огляду
	Coordinate cameraPos(0, 0, -7);
	// напрямок
	Coordinate cameraDir(0, 0, 1);
	//положення проекції на відстані 1 від камери
	Coordinate planeOrigin = cameraPos + cameraDir.singleVector();

	float fov = 60; //кут огляду

	int Width = 100;
	int Height = 100;
	bool** screenBuffer = new bool*[Width];

	for (int i = 0; i < Height; i++)
		screenBuffer[i] = new bool[Height];

	Coordinate A(0, 0, 0);
	Coordinate B(-2, 1, 0);
	Coordinate C(1, 1, 0);
	Triangle triangleToDraw(A, B, C);
	
	for (int x = 0; x < Width; x++){
		for (int y = 0; y < Height; y++){
			screenBuffer[x][y] = false;
			//нормалізуємо координати в інтервал [-1;1]
			float xNorm = (x - Width / 2) / (float)Width;
			float yNorm = -(y - Height / 2) / (float)Height;

			float distanceToPlaneFromCamera = (cameraPos - planeOrigin).length();
			//float distanceToPlaneFromCamera = planeOrigin.distance(cameraPos);
			float fovInRad = fov / (float)180 * M_PI;

			//висота екрану перед камерою 
			float realPlaneHeight = (float)(distanceToPlaneFromCamera * tan(fovInRad));

			Coordinate temp(xNorm * realPlaneHeight / 2, yNorm * realPlaneHeight / 2, 0);
			Coordinate positionOnPlane = planeOrigin + temp;

			Coordinate rayDirection = positionOnPlane - cameraPos;

			// If we find an intersection of the ray with our triangle, we draw "pixel"
			if (ThereIsIntersectionBetweenRayAndTriangle(cameraPos, rayDirection, triangleToDraw))
				screenBuffer[x][y] = true;
		}
	}
	DrawScreenBuffer(Height,Width, screenBuffer);
}

void RayTracer::DrawScreenBuffer(int screenHeight, int screenWidth, bool** screenBuffer)
{
	// Y first, output by rows
	for (int y = 0; y < screenHeight; y++)
	{
		for (int x = 0; x < screenWidth; x++)
		{
			if (screenBuffer[x][y]) 
				cout << "X";
			else
				cout << ".";
		}
		cout << endl;
	}
}


bool RayTracer::ThereIsIntersectionBetweenRayAndTriangle(Coordinate rayOrigin, Coordinate rayVector, Triangle inTriangle){
	Coordinate vertex0 = inTriangle.A;
	Coordinate vertex1 = inTriangle.B;
	Coordinate vertex2 = inTriangle.C;
	Coordinate edge1 = vertex1 - vertex0;
	Coordinate edge2 = vertex2 - vertex0;
	Coordinate h = rayVector.CrossProduct(edge2);
	float a = edge1.DotProduct(h);
	float EPSILON = 1e-5f;
	if (a > -EPSILON && a < EPSILON)
		return false;
	float f = 1 / a;
	Coordinate s = rayOrigin - vertex0;
	float u = f * s.DotProduct(h);
	if (u < 0.0 || u > 1.0)
		return false;
	Coordinate q = s.CrossProduct(edge1);
	float v = f * rayVector.DotProduct(q);
	if (v < 0.0 || u + v > 1.0)
		return false;
	//At this stage we can compute t to find out where the intersection point is on the line.
	float t = f * edge2.DotProduct(q);
	return t > EPSILON;
}