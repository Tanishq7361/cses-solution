/*
    DATE    :   25-09-2024
    Problem :   Number Spiral
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int x, y;
        cin >> x >> y;
        if (x > y)
        {
            if (x % 2 == 0)
            {
                cout << x * x - y + 1 << endl;
            }
            else
            {
                cout << (x - 1) * (x - 1) + y << endl;
            }
        }
        else if (x < y)
        {
            if (y % 2 != 0)
            {
                cout << y * y - x + 1 << endl;
            }
            else
            {
                cout << (y - 1) * (y - 1) + x << endl;
            }
        }
        else if (x == y)
        {
            cout << x * x - x + 1 << endl;
        }
    }
}