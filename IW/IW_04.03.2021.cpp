#include <iostream> 
using namespace std;

void main()
{
    //Variant 1

	//Task 1
    /*
    int n, i, c, a = 1;

    cout << "Enter n: "; 
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        for (c = 1; c <= i; c++)
        {
            cout << a;
            a++;
        }
        cout << endl;
    }
    */

    //Task 2

    int bin, n = 0;

    cout << "Enter bin: ";
    cin >> bin;

    for (int i = 0; bin > 0; i++)
    {
        n = (n * 10) + pow((bin % 10), 2);
        bin /= 10;
    }

    cout << n;
}