// Date : 07-11-2025
 
#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;
 
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
// .find_by_order(k)  returns iterator to kth element starting from 0;
// .order_of_key(k) returns count of elements strictly smaller than k;
 
#define ll long long
#define vll vector<long long>
#define pb push_back
#define pll pair<ll,ll>
#define ff first
#define ss second
 
const int MOD = 1e9 +7;
 
inline bool isPrime(ll n) {
    if(n <= 1) return false; if(n <= 3) return true; if(n % 2 == 0 || n % 3 == 0) return false;
    for(ll i=5; i*i<=n; i+=6) { if(n % i == 0 || n % (i+2) == 0) return false; } return true;
}
inline ll power(ll a, ll b, ll mod = MOD) { ll ans = 1; a %= mod; while(b > 0) { if(b & 1) { ans = (ans * a) % mod; } a = (a * a) % mod; b >>= 1; } return ans; }
inline bool isPowOfTwo(ll n) { return ((n > 0) && !(n & (n - 1))); }
inline bool isPerfectSq(ll n) { if(n < 0) return false; ll sr = static_cast<ll>(sqrt(n)); return (sr*sr == n); }
inline bool compbyss(pair<ll, ll> a, pair<ll, ll> b) { return a.second < b.second; }
inline bool comprev(pair<ll,ll> a, pair<ll,ll> b){if(a.ff==b.ff){return a.ss<b.ss;} else{return a.ff>b.ff;}}
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
struct StringHash {
    string s; int n;
    ll p1 = 313, m1 = 1e9 + 7; ll p2 = 379, m2 = 1e9 + 9;
    vll p_pow1, p_pow2, h1, h2, inv_pow1, inv_pow2;
    StringHash(const string& str) : s(str) {
        n = s.length(); p_pow1.resize(n); p_pow2.resize(n);
        h1.resize(n + 1, 0); h2.resize(n + 1, 0); inv_pow1.resize(n); inv_pow2.resize(n);
        p_pow1[0] = 1; p_pow2[0] = 1; inv_pow1[0] = 1; inv_pow2[0] = 1;
        ll inv_p1 = modinv(p1, m1); ll inv_p2 = modinv(p2, m2);
        for (int i = 1; i < n; i++) {
            p_pow1[i] = (p_pow1[i-1] * p1) % m1; p_pow2[i] = (p_pow2[i-1] * p2) % m2;
            inv_pow1[i] = (inv_pow1[i-1] * inv_p1) % m1; inv_pow2[i] = (inv_pow2[i-1] * inv_p2) % m2;
        }
        for (int i = 0; i < n; i++) {
            h1[i+1] = (h1[i] + (s[i] - 'a' + 1) * p_pow1[i]) % m1;
            h2[i+1] = (h2[i] + (s[i] - 'a' + 1) * p_pow2[i]) % m2;
        }
    }
    pll get_hash(int l, int r) {
        ll res1 = (h1[r+1] - h1[l] + m1) % m1; ll res2 = (h2[r+1] - h2[l] + m2) % m2;
        res1 = (res1 * inv_pow1[l]) % m1; res2 = (res2 * inv_pow2[l]) % m2;
        return make_pair(res1, res2);
    }
};
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s1;
    cin>>s1;
    ll n=s1.size();
    StringHash h1(s1);
    ll ans=0;
    for(int i=0;i<n-1;i++){
        if(h1.get_hash(0,i)==h1.get_hash(n-1-i,n-1)) cout<<i+1<<' ';
    }
    cout<<endl;
}