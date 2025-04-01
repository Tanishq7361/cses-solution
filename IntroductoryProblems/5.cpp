/*
    DATE    :   25-09-2024
    Problem :   Permutations
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n==1){
        cout<<1;
    }
    else if (n <= 3)
    {
        cout << "NO SOLUTION";
    }
    else
    {
        if (n % 2 == 0)
        {
            for (int i = 2; i <= n; i += 2)
            {
                cout << i << " ";
            }
            for (int j = 1; j < n; j += 2)
            {
                cout << j << " ";
            }
        }
        else
        {
            for (int i = 2; i < n; i += 2)
            {
                cout << i << " ";
            }
            for (int j = 1; j <= n; j += 2)
            {
                cout << j << " ";
            }
        }
    }
}