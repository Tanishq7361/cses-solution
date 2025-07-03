/*
    DATE    :   25-09-2024
    Problem :   Coin Piles
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        long long int a, b;
        cin >> a >> b;
        if (2 * a < b || 2 * b < a)
        {
            cout << "NO" << endl;
        }
        else
        {
            if ((a == 0 && b != 0) || (a != 0 && b == 0))
            {
                cout << "NO" << endl;
            }
            else if (a % 3 == 0 && b % 3 == 0)
            {
                cout << "YES" << endl;
            }
            else if (a % 3 == 1 && b % 3 == 2)
            {
                cout << "YES" << endl;
            }
            else if (a % 3 == 2 && b % 3 == 1)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}