// created: 05.08.2025

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

using namespace std;
using namespace __gnu_pbds;

template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

// .find_by_order(k)  returns iterator to kth element starting from 0;
// .order_of_key(k) returns count of elements strictly smaller than k;

#define TRACE
#ifdef TRACE
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1<<" | ";
        __f(comma+1, args...);
    }
#else
    #define trace(...) 1
#endif
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
const int N=1e6;

#define endl '\n'
#define ll long long
#define stc static_cast
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll,ll>>
#define pll pair<ll, ll>
#define ppll pair<pair<ll,ll>,ll>
#define pllp pair<ll,pair<ll,ll>>
#define umll unordered_map<ll,ll,custom_hash>
#define pb push_back
#define ppb pop_back
#define bitcnt __builtin_popcountll
#define ff first
#define ss second
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define one cout << "1\n"
#define mone cout << "-1\n"
#define zro cout << "0\n"
#define ent cout << endl
#define done return
#define fr(i, l, r) for (ll i = (l); i < (r); i++)
#define frr(i, r, l) for (ll i = (r - 1); i >= l; i--)
#define sz(x) ll((x).size()) 
#define all(x) (x).begin(), (x).end()
#define srt(x) sort((x).begin(), (x).end())
#define rsrt(x) sort((x).rbegin(), (x).rend())
#define rev(x) reverse(x.begin(), x.end())
#define maxval(v) *max_element((v).begin(), (v).end())
#define minval(v) *min_element((v).begin(), (v).end())
#define maxid(v) max_element((v).begin(), (v).end()) - ((v).begin())
#define minid(v) min_element((v).begin(), (v).end()) - ((v).begin())

#define in(T,n) \
    T n;     \
    cin >> n
#define in2(T,n,k) \
    T n, k;      \
    cin >> n >> k
#define in3(T,a,b,c) \
    T a, b, c;      \
    cin >> a >> b >> c
#define in4(T,a,b,c,d) \
    T a, b, c, d;      \
    cin >> a >> b >> c >> d
#define vin(a, n)              \
    vll a(n);                  \
    for (ll i = 0; i < n; i++) \
        cin >> a[i];
#define vvin(a, n, m)              \
    vvll a(n, vll(m));             \
    for (ll i = 0; i < n; i++)     \
    {                              \
        for (ll j = 0; j < m; j++) \
        {                          \
            cin >> a[i][j];        \
        }                          \
    }                              
#define vout(a)           \
    for (auto x : a)      \
    {                     \
        cout << x << ' '; \
    }                     \
    cout << '\n';
#define vpout(a)           \
    for (pair<ll,ll> x : a)      \
    {                     \
        cout << x.ff << ' '<<x.ss<<endl; \
    }                     \
    cout << '\n';
#define o1(a) cout << a << '\n'
#define o2(a, b) cout << a << ' ' << b << '\n'
#define o3(a, b, c) cout << a << ' ' << b << ' ' << c << '\n'
#define o4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'


// rotate(v.begin(),v.begin()+v.size()-r,v.end()); for rotating vector r times right
// rotate(v.begin(),v.begin()+r,v.end()); for rotating vector r times left
// Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
// Or use gp_hash_table<X,null_type>


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
inline ll ansXor(ll n){
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}
inline ll cntinv(vll &a){
    ordered_set<ll> s;
    ll ans = 0;
    ll z = a.size();
    frr(i, z, 0){
        ans += s.order_of_key(a[i]);
        s.insert(a[i]);
    }
    return ans;
}


void solve()
{
    vector<ll>fact(1e6+1);
    fact[0]=1;
    for(int i=1;i<=1e6;i++){
        fact[i]=(fact[i-1]*i)%MOD;
    }
    in3(ll,a,b,n);
    ll sum=a*n;
    ll ans=0;
    for(int i=0;i<=n;i++){
        bool f1=true;
        ll temp=sum;
        while(temp>0){
            ll z=temp%10;
            if(z!=a && z!=b){
                f1=false;
                break;
            }
            temp/=10;
        }
        if(f1){
            ans=modadd(ans,modmult(fact[n],modinv(modmult(fact[i],fact[n-i]))));
        }
        sum+=b-a;
    }
    o1(ans);
}


signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //cout << fixed << setprecision(25);
    cerr << fixed << setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();
    ll tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solve();
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cerr << "Time Taken: " << ((long double)duration.count())/((long double) 1e9) << " sec.\n";
    return 0;
}

