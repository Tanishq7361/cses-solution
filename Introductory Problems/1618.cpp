/*
    DATE    :   25-09-2024
    Problem :   Trailing zeroes
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;
    int ct = 0;
    while (n > 0)
    {
        n = n / 5;
        ct += n;
    }
    cout << ct;
}