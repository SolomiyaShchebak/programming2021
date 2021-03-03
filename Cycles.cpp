#include <iostream> 
using namespace std;

int sumOfDigits(int n)
{
	int s = 0;
	n = abs(n);
	while (n)
	{
		s += n % 10;
		n /= 10;
	}
	return s;
}

bool isPrime(int n)
{
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

void main()
{
	//Task 1. Sum of sqrts
	/*
	int n; float sum = 0;
	cout << "Enter n: " << endl;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		sum += sqrt(i);
	}
	cout << "Final sum: " << sum;
	*/

	//Task 2. Sum of digits in a number
	/*
	int n, s = 0;
	cout << "Enter n: " << endl;
	cin >> n;
	
	cout << "Sum of digits: " << sumOfDigits(n);
	*/

	//Task 3. Multiplication of numbers ending with zero
	/*
	int n, d = 1;
	cout << "Enter numbers (ends with zero): ";

	do {
		cin >> n;
		if (n != 0)
			d *= n;
	} while (n != 0);

	cout << "Result of multiplication: " << d;
	*/

	//Task 4. Print letters of Eng. alphabet in triplets;
	/*
	char ch;
	for (char c = 'a'; c <= 'z'; c++)
	{
		for (char c2 = c; (c2 <= c + 3) && (c2 <= 'z'); c2++)
			cout << c2;
		cout << endl;
	}
	*/

	//HW. Print all divisors of N, except 1 and N
	/*
	int n;
	cout << "Enter n: ";
	cin >> n;

	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			cout << i << endl;
	}
	*/

	//Вивести всі прості числа з діапазону заданого користувачем (дійсні числа). 
	//написати функцію для перевірки простоти числа.
	/*
	cout << isPrime(9) << '\t' << isPrime(5) << endl;
	float a, b;

	cout << "Enter the beginning and the end of the range: " << endl;
	cin >> a >> b;

	a = 1; b = int(b);
	cout << a << b << endl;

	for (a; a <= b; a++)
	{
		if (isPrime(a) == true)
			cout << a << ' ';
	}
	*/
}