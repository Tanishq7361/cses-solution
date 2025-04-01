/*
    DATE    :   25-09-2024
    Problem :   Missing Number
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, sum = 0, summax;
    cin >> n;
    long long int z=n-1;
    summax = n * (n + 1) / 2;
    while (z--)
    {
        long long int t;
        cin >> t;
        sum += t;
    }
    cout<<summax-sum;
}
