// Date : 17-12-2025

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 +7;

inline bool isPrime(ll n) {
    if(n <= 1) return false; if(n <= 3) return true; if(n % 2 == 0 || n % 3 == 0) return false;
    for(ll i=5; i*i<=n; i+=6) { if(n % i == 0 || n % (i+2) == 0) return false; } return true;
}
inline ll power(ll a, ll b, ll mod = MOD) { ll ans = 1; a %= mod; while(b > 0) { if(b & 1) { ans = (ans * a) % mod; } a = (a * a) % mod; b >>= 1; } return ans; }
inline bool isPowOfTwo(ll n) { return ((n > 0) && !(n & (n - 1))); }
inline bool isPerfectSq(ll n) { if(n < 0) return false; ll sr = static_cast<ll>(sqrt(n)); return (sr*sr == n); }
inline bool compbyss(pair<ll, ll> a, pair<ll, ll> b) { return a.second < b.second; }
inline bool comprev(pair<ll,ll> a, pair<ll,ll> b){if(a.first==b.first){return a.second<b.second;} else{return a.first>b.first;}}
inline ll modadd(ll a, ll b, ll mod = MOD) { return ((a % mod + b % mod) % mod); }
inline ll modmult(ll a, ll b, ll mod = MOD) { return ((a % mod * b % mod) % mod); }
inline ll modinv(ll a, ll mod = MOD) { return power(a, mod - 2, mod); }
inline ll moddiv(ll a, ll b, ll mod = MOD) { return modmult(a, modinv(b, mod), mod); }
inline ll msbPos(ll n){ if (n == 0) return -1; return(63 - (__builtin_clzll(n)));}
inline ll gcd(ll a, ll b) { if(b == 0) return a; return gcd(b, a % b); }
inline ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
inline ll getBit(ll n, ll pos) { return ((n >> pos) & 1); }
inline ll setBit(ll n, ll pos) { return (n | (1 << pos)); }
inline ll clearBit(ll n, ll pos) { return (n & (~(1 << pos))); }
inline ll toggleBit(ll n, ll pos) { return (n ^ (1 << pos)); }
inline ll turnOffRightmostSetBit(ll n) { return (n & (n - 1)); }
inline bool isBitSet(ll n, ll p) { return (n & (1LL << p)) != 0; }
inline ll ansXor(ll n){
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

//------------------------------Computing------------------------------//
class calc{
private:
    ll mod;
    vector<ll>pfact,invpfact,der;
public:
    calc(ll n, ll p):mod(p){
        pfact.resize(n+1,1),invpfact.resize(n+1,1),der.resize(n+1);
        for(int i=1;i<=n;i++){pfact[i]=(pfact[i-1]*i)%mod;}
        invpfact[n]=modinv(pfact[n],mod);
        for(int i=n-1;i>=1;i--){invpfact[i]=(invpfact[i+1]*(i+1))%mod;}
        if(n>=2) der[2]=1;
        for(int i=3;i<=n;i++){der[i]=((i-1)*(der[i-1]+der[i-2])%mod)%mod;}
    }
    ll ncr(ll n, ll r){
        if(r>n || r<0) return 0;
        return (((pfact[n]*invpfact[r])%mod)*invpfact[n-r])%mod;
    }
    ll npr(ll n, ll r){
        if(r>n || r<0) return 0;
        return (pfact[n]*invpfact[n-r])%mod;
    }
    ll getpfact(ll n){return pfact[n];}
    ll getinvpfact(ll n){return invpfact[n];}
    ll getder(ll n){return der[n];}
    ll rust(ll n, ll r){
        if(r<0 || r>n) return 0;
        if(n==0 || r==0) return 1;
        return ncr(n%mod,r%mod)*rust(n/mod,r/mod)%mod;
    }
};
//-------------------------------------------------------------------------//

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    calc x(n,MOD);
    if(n&1){
        cout<<0<<endl;
    }
    else{
        ll ans=x.ncr(n,n/2);
        ans=ans*modinv(n/2 +1);
        ans%=MOD;
        cout<<ans<<endl;
    }
}