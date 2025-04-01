///////////////////////////////////////////////////////////////////////////////////////////

// Date : 31-01-2025
// problem : Exponentation-2

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>
const ll MOD = 1e9 + 7;

ll power(ll x, ll y)
{
    ll res = 1;
    x = x % MOD;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if(c==0){
            if(b==0){
                cout<<1<<endl;
            }
            else{
                cout<<a%MOD<<endl;
            }
        }
        else if(b==0){
            cout<<1<<endl;
        }
        else{
            cout << power(a, power(b, c))%MOD << endl;
        }
    }
}