#include "Header.h"

void readInfo(const char* fname, int& size, Study*& arr)
{
	ifstream fin(fname);

	fin >> size;

	arr = new Study[size];

	char name[SIZE];
	char city[SIZE];
	int age;
	int quantity;

	for (int i = 0; i < size; i++)
	{
		try
		{
			fin.get();
			fin.get(name, SIZE, ',');
			fin.get(); 
			fin.get(city, SIZE, ',');
			fin.get();
			fin >> age;
			fin.get();
			fin >> quantity;
			arr[i] = Study(name, city, age, quantity);
		}

		catch (const char* error)
		{
			cout << "Error: " << error << endl;
			i--;
			size--;
		}

		catch (...)
		{
			cout << "Unexpected error!";
		}
	}

	fin.close();
}

void writeArray(Study* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i].WriteToConsole();
	}
}

void writeToFile(const char* fname, int size, Study* arr)
{
	ofstream fout(fname);
	for (int i = 0; i < size; i++)
	{
		fout << arr[i].Name << " ";
		fout << arr[i].City << " ";
		fout << arr[i].Year << " ";
		fout << arr[i].Quantity << endl;
	}

	fout.close();
}

void sort(Study*& arr, int& size) 
{
    for (int i = 0; i < size; i++) 
    {
        for (int j = i; j < size; j++) 
        {
			if (arr[i].City > arr[j].City)
			{
			Study temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			}

            if (arr[i].Quantity > arr[j].Quantity) 
            {
                Study temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

Study& findMinYear(Study* arr, int size)
{
	int min = arr[0].Year;
	int min_index = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i].Year < min)
		{
			min = arr[i].Year;
			min_index = i;
		}
	}

	return arr[min_index];
}

void testTask1()
{
	Study* arr;
	int size;

	readInfo("1_in.txt", size, arr);
	writeArray(arr, size);
	sort(arr, size);
	writeToFile("1_out.txt", size, arr);
	cout << "\nThe oldest university: " << endl;
	findMinYear(arr, size).WriteToConsole();
}

void main()
{
	testTask1();
}