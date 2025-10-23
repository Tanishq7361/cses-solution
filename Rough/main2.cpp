// created: 13.10.2025

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
// #include<atcoder/all>

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;

template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// .find_by_order(k)  returns iterator to kth element starting from 0;
// .order_of_key(k) returns count of elements strictly smaller than k;

struct custom_hash { //to avoid TLE due to collision in unordered_map
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    template<typename L, typename R>
    size_t operator()(pair<L,R> const& Y) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31 + Y.second + FIXED_RANDOM);
    }
};

const long long  MOD = 1e9 + 7;
const long long  MOD1 = 998244353;

#define endl '\n'
#define ll   long long
#define stc  static_cast
#define vll  vector<ll>
#define vbl  vector<bool>
#define vsl  vector<string>
#define vbll vector<vector<bool>>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll,ll>>
#define pll  pair<ll, ll>
#define umll unordered_map<ll,ll,custom_hash>
#define pb   push_back
#define bitcnt __builtin_popcountll
#define ff   first
#define ss   second
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define mone cout << "-1\n"
#define zro cout << "0\n"
#define done return
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define repr(i, r, l) for (ll i = (r - 1); i >= l; i--)
#define all(x) (x).begin(), (x).end()
#define srt(x) sort((x).begin(), (x).end())
#define rsrt(x) sort((x).rbegin(), (x).rend())
#define rev(x) reverse(x.begin(), x.end())
#define maxval(v) *max_element((v).begin(), (v).end())
#define minval(v) *min_element((v).begin(), (v).end())
#define maxid(v) max_element((v).begin(), (v).end()) - ((v).begin())
#define minid(v) min_element((v).begin(), (v).end()) - ((v).begin())
template<class T> int LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> int UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
using u32=unsigned int;
using u64=unsigned long long;
using i128=__int128;
using u128=unsigned __int128;
using f128=__float128;
#define vin(T, a, n)              \
    vector<T> a(n);                  \
    for (ll i = 0; i < n; i++) \
        cin >> a[i];
#define vin1(T, a, n)              \
    vector<T> a(n+1);                  \
    for (ll i = 1; i <=n; i++) \
        cin >> a[i];
#define mem(n, i) memset(n, i, sizeof n)
#define vpin(a, n)               \
    vpll a(n);                   \
    for (ll i = 0; i < n; i++)   \
        cin >> a[i].ff >> a[i].ss;
#define vvin(T, a, n, m)              \
    vector<vector<T>> a(n, vector<T>(m)); \
    for (ll i = 0; i < n; i++)     \
        for (ll j = 0; j < m; j++) \
             cin >> a[i][j];          
template<class T>void vout(vector<T> &n){for(int i=0;i<int(n.size());i++){cout<<n[i]<<" ";}cout<<'\n';}
template<class T>void vout(vector<vector<T>> &n){for(int i=0;i<int(n.size());i++){for(int j=0;j<int(n[i].size());j++){cout<<n[i][j]<<" ";}cout<<'\n';}cout<<'\n';}
#define o1(a) cout << a << '\n'

// rotate(v.begin(),v.begin()+v.size()-r,v.end()); for rotating vector r times right
// rotate(v.begin(),v.begin()+r,v.end()); for rotating vector r times left
// Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
// Or use gp_hash_table<X,null_type>
// multiset.erase removes all occurence
// multiset.erase(multiset.find()) removes first occurence

inline ll cntinv(vll &a){
    ordered_set<ll> s;
    ll ans = 0;
    repr(i, a.size(), 0){
        ans += s.order_of_key(a[i]);
        s.insert(a[i]);
    }
    return ans;
}
vector<ll>dx={1,-1,0,0,1,1,-1,-1};
vector<ll>dy={0,0,1,-1,1,-1,1,-1};
inline bool isPrime(ll n) {
    if(n <= 1) return false; if(n <= 3) return true; if(n % 2 == 0 || n % 3 == 0) return false;
    for(ll i=5; i*i<=n; i+=6) { if(n % i == 0 || n % (i+2) == 0) return false; } return true;}
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
inline ll ansXor(ll n){ return n % 4 == 0 ? n : n % 4 == 1 ? 1 : n % 4 == 2 ? n + 1 : 0; }
vll fact,invfact;
void precompp(ll n){
    fact.resize(n+1),invfact.resize(n+1);
    fact[0]=invfact[0]=1;
    rep(i,1,n+1){fact[i]=(fact[i-1]*i)%MOD;}
    invfact[n] = modinv(fact[n], MOD);
    repr(i,n,1) invfact[i] = (invfact[i+1]*(i+1))%MOD;
}

bool palin(string &s){
    ll z=s.size();
    rep(i,0,z/2){
        if(s[i]!=s[z-i-1]){
            return false;
        }
    }
    if(z&1 && s[z/2]=='1'){return false;}
    return true;
}

void solve()
{
    ll n;
    cin>>n;
    ll w=bitcnt(n);
    if(w&1){no;done;}
    string ans="";
    ll z=n;
    while(z>0){
        if(z&1){
            ans.pb('1');
        }
        else{
            ans.pb('0');
        }
        z/=2;
    }
    rep(i,0,64){
        if(palin(ans)){
            yes;
            done;
        }
        else{
            ans.pb('0');
        }
    }
    no;
    
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // cout << fixed << setprecision(25);
    cerr << fixed << setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();
    // precompp(n);
    ll tt = 1;
    cin >> tt;
    while (tt--)
    { solve(); }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cerr << "Time Taken: " << ((long double)duration.count())/((long double) 1e9) << " sec.\n";
    return 0;
}