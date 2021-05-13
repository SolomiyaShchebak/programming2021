#pragma once
#define SIZE 50
#include <iostream>
#include <fstream>
using namespace std;

struct Study
{
	char Name[SIZE];
	char City[SIZE];
	int Year;
	int Quantity;

	Study(const char* name = "", const char* city = "", int year = 2021, int quantity = 1);

	void WriteToConsole();
};