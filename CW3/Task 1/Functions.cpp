#include "Header.h"
#define SIZE 50

Study::Study(const char* name, const char* city, int year, int quantity)
{
	strcpy_s(Name, SIZE, name);
	strcpy_s(City, SIZE, city);

	Year = year;

	if (quantity < 0)
		throw "Quantity of students < 0";

	Quantity = quantity;
}

void Study::WriteToConsole()
{
	cout << "University: " << Name << " " << City << " " << Year << " " << Quantity << endl;
}