/*
    DATE    :   04-10-2024
    Problem :   Two Knights
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, fac, sum, z;
    cin >> n;

    for (int k = 1; k <= n; k++)
    {
        z = k * k;
        fac = ((z) * (z - 1)) / 2;
        sum = (2 * (k - 1)) - 1;
        cout << fac - ((sum * sum) - 1)<<endl;
    }
}