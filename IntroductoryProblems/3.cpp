/*
    DATE    :   20-09-2024
    Problem :   Repetitions
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size(), ct = 1, ctmax = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            ct++;
        }
        else
        {
            ctmax = max(ct, ctmax);
            ct=1;
        }
        ctmax=max(ct,ctmax);
    }
    cout<<ctmax;
}