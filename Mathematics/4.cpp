///////////////////////////////////////////////////////////////////////////////////////////

// Date : 31-01-2025
// problem : Counting Divisors

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>
int main()
{
    ll n;
    cin >> n;
    while (n--)
    {
        ll x;
        cin >> x;
        ll ans = 2;
        for (ll i = 1; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                ans++;
                if (i != x / i)
                    ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}