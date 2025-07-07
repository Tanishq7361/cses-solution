///////////////////////////////////////////////////////////////////////////////////////////

// Date : 06-07-2025
// problem : Creating strings 2

#include <bits/stdc++.h>
using namespace std;

const long long  MOD = 1e9 + 7;
#define ll long long
#define vll vector<ll>
#define ff first
#define ss second

inline ll power(ll a, ll b, ll mod = MOD) { ll ans = 1; a %= mod; while(b > 0) { if(b & 1) { ans = (ans * a) % mod; } a = (a * a) % mod; b >>= 1; } return ans; }
inline ll modmult(ll a, ll b, ll mod = MOD) { return ((a % mod * b % mod) % mod); }
inline ll modinv(ll a, ll mod = MOD) { return power(a, mod - 2, mod); }
inline ll moddiv(ll a, ll b, ll mod = MOD) { return modmult(a, modinv(b, mod), mod); }

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    cin>>s;
    unordered_map<char,ll>mpp;
    ll n=s.size();
    for(int i=0;i<n;i++){
        mpp[s[i]]++;
    }
    vll fact(n+1);
    fact[0]=1;
    for(int i=1;i<=n;i++){
        fact[i]=(fact[i-1]*i)%MOD;
    }
    ll z=1;
    for(auto x:mpp){
        z=modmult(z,fact[x.ss]);
    }
    ll ans=moddiv(fact[n],z);
    cout<<ans<<endl;
}