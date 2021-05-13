#include "Header.h"

Line::Line(const float k, const float b)
{
	K = k;
	B = b;
}

bool Line::BelongsToLine(float x, float y)
{
	if (K * x + B == y)
		return true;

	return false;
}