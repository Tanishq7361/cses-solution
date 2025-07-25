///////////////////////////////////////////////////////////////////////////////////////////
 
// Date : 06-07-2025
// problem : Sum of Divisor
 
#include <bits/stdc++.h>
using namespace std;

const long long  MOD = 1e9 + 7;

#define endl '\n'
#define ll long long

inline ll power(ll a, ll b, ll mod = MOD) { ll ans = 1; a %= mod; while(b > 0) { if(b & 1) { ans = (ans * a) % mod; } a = (a * a) % mod; b >>= 1; } return ans; }
inline ll modadd(ll a, ll b, ll mod = MOD) { return ((a % mod + b % mod) % mod); }
inline ll modmult(ll a, ll b, ll mod = MOD) { return ((a % mod * b % mod) % mod); }
inline ll modinv(ll a, ll mod = MOD) { return power(a, mod - 2, mod); }
inline ll moddiv(ll a, ll b, ll mod = MOD) { return modmult(a, modinv(b, mod), mod); }
inline ll msbPos(ll n){ if (n == 0) return -1; return(63 - (__builtin_clzll(n)));}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll ans=0;
    ll z=sqrt(n);
    for(int i=1;i<=z;i++){
        ans=modadd(ans,modmult(i,(n/i)));
        
    }
    cout<<ans<<endl;
    return 0;
}