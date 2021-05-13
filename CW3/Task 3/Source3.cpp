#include "Header.h"

void testTask3()
{
	Line line(-1, 1);

	float x = 2, y = 3;

	if(line.BelongsToLine(x, y))
		cout << "Point (" << x << ", " << y << ") BELONGS to line y = " << line.K << "x + " << line.B << endl;
	else
		cout << "Point (" << x << ", " << y << ") DOESN'T BELONG to line y = " << line.K << "x + " << line.B << endl;
}

void main()
{
	testTask3();
}