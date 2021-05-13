#pragma once
#pragma once
#define SIZE 50
#include <iostream>
#include <fstream>
using namespace std;

struct Line // y = kx + b
{
	float K;
	float B;

	Line(const float k = 0, const float b = 0);

	bool BelongsToLine(float x, float y);
};