///////////////////////////////////////////////////////////////////////////////////////////

// Date : 06-07-2025
// problem : Distributing Apples

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
    ll n,m;
    cin>>n>>m;
    ll temp=1;
    ll x,y,z;
    for(int i=1;i<= n+m-1;i++){
        temp=modmult(temp,i);
        if(i==n+m-1){
            z=temp;
        }
        if(i==m){
            y=temp;
        }
        if(i==n-1){
            x=temp;
        }
    }
    ll w=modmult(x,y);
    ll ans=moddiv(z,w);
    cout<<ans<<endl;
}