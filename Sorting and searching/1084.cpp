///////////////////////////////////////////////////////////////////////////////////////////
// Date : 23-11-2024
// problem : Apartments

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>
int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll b[n], c[m];
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> c[i];
    }
    sort(b, b + n);
    sort(c, c + m);
    ll j = 0, p = 0;
    ll ans = 0;

    while (j < n && p < m)
    {
        if (b[j] - c[p] <= k && b[j] - c[p] >= -k)
        {
            ans++;
            j++;
            p++;
        }
        else if (b[j] - c[p] < -k)
        {
            j++;
        }
        else if (b[j] - c[p] > k)
        {
            p++;
        }
        
    }
    cout << ans << endl;
}