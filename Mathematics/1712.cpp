///////////////////////////////////////////////////////////////////////////////////////////
 
// Date : 07-06-2025
// problem : Exponentation-2
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define vll vector<long long int>
const ll MOD = 1e9 + 7;
 
inline ll power(ll a, ll b, ll mod = MOD) { ll ans = 1; a %= mod; while(b > 0) { if(b & 1) { ans = (ans * a) % mod; } a = (a * a) % mod; b >>= 1; } return ans; }
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if(c==0){
            cout<<a<<endl;
        }
        else if(b==0){
            cout<<1<<endl;
        }
        else if(a==0){
            cout<<0<<endl;
        }
        else{
            // I didn't know to i read in some article that it is Fermat's Little Theorem optimization if m is prime for a^(b^c)%m
            ll phi=MOD-1;// Euler's theorem if m is prime
            ll z=power(b,c,phi); // reduce exponent mod phi(m)
            ll y=power(a,z,MOD);
            cout<<y<<endl;
        }
    }
}