/*
    DATE    :   30-09-2024
    Problem :   Two Sets
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int ct = 0;

void ste(int n)
{
    if (n % 4 == 1 || n % 4 == 2)
    {
        cout << "NO" << endl;
    }
    else
    {
        ct++;
        cout << "YES" << endl;
    }
}
void even(int n)
{
    cout << n / 2 << endl;
    for (int i = 1; i <= n; i += 4)
    {
        cout << i << " ";
    }
    for (int i = 4; i <= n; i += 4)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << n / 2 << endl;
    for (int i = 3; i <= n; i += 4)
    {
        cout << i << " ";
    }
    for (int i = 2; i <= n; i += 4)
    {
        cout << i << " ";
    }
    cout << endl;
}
void odd(int n)
{

    cout << (n / 2) + 1 << endl;
    for (int i = 1; i <= n; i += 4)
    {
        cout << i << " ";
    }
    for (int i = 2; i <= n; i += 4)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << n / 2 << endl;
    for (int i = 3; i <= n; i += 4)
    {
        cout << i << " ";
    }
    for (int i = 4; i <= n; i += 4)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    ste(n);
    if (n % 4 == 0)
        even(n);
    if (n % 4 == 3)
        odd(n);
}