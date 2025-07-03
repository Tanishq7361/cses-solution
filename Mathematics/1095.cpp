///////////////////////////////////////////////////////////////////////////////////////////
// Date : 24-11-2024
// problem : Exponentiation

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>
const ll mod = 1e9 + 7;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        if (b == 0)
        {
            cout << 1 << endl;
        }
        else if (a == 1 || a == 0)
        {
            cout << a << endl;
        }
        else
        {
            ll ans = 1;
            while (b > 0)
            {
                if (b % 2 == 1)
                {
                    ans = (ans * a) % mod;
                }
                a = (a * a) % mod;
                b /= 2;
            }
            cout<<ans<<endl;
        }
    }
}