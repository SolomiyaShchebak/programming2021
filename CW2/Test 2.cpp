#include <iostream>
using namespace std;

void manualFill(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "[" << i + 1 << "]" << ": ";
		cin >> arr[i];
	}
}

void printArr(int* arr, int b, int size)
{
	for (int i = b; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int** createMatrix(int n, int m)
{
	int** matrix = new int* [n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m];
	}

	return matrix;
}

void manualFillMatrix(int** matrix, int n, int m)
{
	cout << "Enter elements of matrix: ";

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

void printMatrix(int** matrix, int n, int m)
{
	cout << "Matrix is: " << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void deleteMatrix(int** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}

//Task 1

void task1(int* arr, int size)
{
	for (int i = 1; i < size; i++)
	{
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && (arr[j] > 0))
		{
			arr[j + 1] = arr[j];
			arr[j] = key;
			j--;
		}
	}
}

void task1Complete()
{
	int size;
	cout << "Enter size of array: "; cin >> size;

	int* arr = new int[size];
	manualFill(arr, size);

	cout << "\nArray is: " << endl;
	printArr(arr, 0, size);

	task1(arr, size);
	cout << "\nArray after change is: " << endl;
	printArr(arr, 0, size);

	delete[] arr;
}

//Task 2

int countOne(int** matrix, int k, int n)
{
	int count = 0;

	for (int i = k; i < n; i++)
	{
		for (int j = k; j < n; j++)
		{
			if (matrix[i][j] == 1)
				count++;
		}
	}
	return count;
}

void task2Complete()
{
	int** matrix;
	int n, m;
	cout << "Enter n (rows): "; cin >> n;
	cout << "Enter m (columns): "; cin >> m;

	matrix = createMatrix(n, m);
	manualFillMatrix(matrix, n, m);

	cout << endl;
	printMatrix(matrix, n, m);

	int k;
	cout << "Enter k: "; cin >> k;

	int max = 0, maxi, maxj;

	for (int i = 0 + k; i < n; i++) 
	{
		for (int j = 0 + k; j < m; j++)
		{
			if (countOne(matrix, i + k, n) > max)
				max = countOne(matrix, i + k, n);
				maxi = i; maxj = j;
		}
	}

	for (int i = maxi; i <= maxi + k; i++)
	{
		for (int j = maxj; j < maxj + k; j++)
		{
			cout << matrix[i][j] << " ";
		}

		cout << endl;
	}

	deleteMatrix(matrix, n);
}

//Task 3

void task3(int* arr, int size, int k)
{
	int temp, v;
	v = 0;

	while (v++ < k)
	{
		temp = arr[size - 1];
		for (int i = size - 1; i >= 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[0] = temp;
	}
}

void task3Complete()
{
	int size, k;
	cout << "Enter size of array: "; cin >> size;

	int* arr = new int[size];
	manualFill(arr, size);

	cout << "\nArray is: " << endl;
	printArr(arr, 0, size);

	cout << "\nEnter k: "; cin >> k;

	task3(arr, size, k);

	cout << "\nArray after change: \n";
	printArr(arr, 0, size);

	delete[] arr;
}

void main()
{
	//task1Complete();

	//task2Complete();

	//task3Complete();
}