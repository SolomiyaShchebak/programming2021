#include<iostream>
using namespace std;

float task1sum(int n, int x)
{
    int p = 1, j = 0;
    float s = 0.0;

    for (j; j <= n; j++)
    {
        p = 1 * pow(10, n + 1 - j);
        s += float((x % p) / (pow(10, n - j)));
        x /= pow(10, n + 1 - j);
    }
    return s;
}

void task1print()
{
    int x, n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter a row of digits (without spaces): ";
    cin >> x;

    cout << "Sum is: " << task1sum(n, x);
}

int task2(int n)
{
    int k = 0; 
    int p = 1;
    for (int i = 9; i > 1; --i)
    {
        while (n % i == 0)
        {
            k += i * p;
            p *= 10;
            n /= i;
        }
    }
    return k;
}

void task2print()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Result: " << task2(n);
}

float task3element(int i)
{
    int res0 = 1, res1 = -1;
    int res = 0, temp, j;
    if (i == 0)
        return 1;
    if (i == 1)
        return -1;

    for (j = 2; j <= i; j++)
    {
        temp = res1;
        res = ((-res1) - 1) + (4 * pow(res0, 2)) + 1;
        res1 = res;
        res0 = temp;
    }
    return res; 
}

int task3sum(int n)
{
    int sum = 0;
    if (n == 1)
        return sum;

    for (int i = 1; i <= n; i++)
    {
        sum = task3element(i) + task3sum(i - 1);
    }
    return sum;
}

void task3print()
{
    int n, sum;
    cout << "Enter n: ";
    cin >> n;

    sum = task3sum(n);
    cout << "Final sum: " << sum;
}

void main()
{
    cout << "Task 1" << endl;
    task1print();
    cout << '\n' << '\n';

    cout << "Task 2" << endl;
    task2print();
    cout << '\n' << '\n';
	
    cout << "Task 3" << endl;
    task3print();
}