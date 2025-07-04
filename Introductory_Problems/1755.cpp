/*
    DATE    :   30-09-2024
    Problem :   Palindrome Reorder
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int hash[93] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[s[i]]++;
    }

    int ct = 0;
    for (int i = 65; i < 93; i++)
    {
        if (hash[i] % 2 != 0)
        {
            ct++;
        }
    }

    if (((n % 2 == 0) && (ct == 0)) || ((n % 2 != 0) && (ct == 1)))
    {
        for (int i = 65; i < 93; i++)
        {

            for (int j = 0; j < (hash[i] / 2); j++)
            {
                cout << (char)i;
            }
        }
        for (int i = 65; i < 93; i++)
        {
            if (hash[i] % 2 != 0)
            {
                cout << (char)i;
            }
        }
        for (int i = 92; i >= 65; i--)
        {

            for (int j = 0; j < (hash[i] / 2); j++)
            {
                cout << (char)i;
            }
        }
    }
    else
    {
        cout << "NO SOLUTION";
    }
}