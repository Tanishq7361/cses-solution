///////////////////////////////////////////////////////////////////////////////////////////
// Date : 23-11-2024
// problem : concert tickets

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<long long int>

int main()
{
    ll n, m;
    vll h(n), t(m);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> t[i];
    }
    sort(h.begin(), h.end());
    
}