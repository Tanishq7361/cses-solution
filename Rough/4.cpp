// created: 06.07.2025

#include <bits/stdc++.h>
using namespace std;

#define King_T ios_base::sync_with_stdio(0);\
    cin.tie(0); \
    cout.tie(0);
#define endl '\n'
#define ll long long
#define stc static_cast
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define vld vector<long double>
#define vcs vector<string>
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define umll unordered_map<ll, ll>
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define bitcount __builtin_popcountll
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
#define maxhp(T) priority_queue<T>
#define minhp(T) priority_queue<T, vector<T>, greater<T>>
#define str(s) \
    string s;  \
    cin >> s
#define in(n) \
    ll n;     \
    cin >> n
#define inn(n, k) \
    ll n, k;      \
    cin >> n >> k
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
#define out(a) cout << a << '\n';
#define sze(x) ll((x).size()) 
#define all(x) (x).begin(), (x).end()
#define srt(x) sort((x).begin(), (x).end())
#define rsrt(x) sort((x).rbegin(), (x).rend())
#define rev(x) reverse(x.begin(), x.end())
#define maxval(v) *max_element((v).begin(), (v).end())
#define minval(v) *min_element((v).begin(), (v).end())
#define maxid(v) max_element((v).begin(), (v).end()) - ((v).begin())
#define minid(v) min_element((v).begin(), (v).end()) - ((v).begin())
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18 + 9;
const ll MOD = 1e9 + 7;
const ll MOD1 = 998244353;
const ll N = 1e6+5;

// rotate(v.begin(),v.begin()+v.size()-r,v.end()); for rotating vector r times right
// rotate(v.begin(),v.begin()+r,v.end()); for rotating vector r times left

inline bool isPrime(ll n) {
    if(n <= 1) return false; if(n <= 3) return true; if(n % 2 == 0 || n % 3 == 0) return false;
    for(ll i=5; i*i<=n; i+=6) { if(n % i == 0 || n % (i+2) == 0) return false; } return true;
}
void SieveOfEratosthenes(ll n, vector<ll> &v)
{
    vector<bool> prime(n + 1, true);
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p])
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])
            v.emplace_back(p);
}
vector<bool> sieve(ll n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (ll j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return isPrime;
}
inline ll power(ll a, ll b, ll mod = MOD) { ll ans = 1; a %= mod; while(b > 0) { if(b & 1) { ans = (ans * a) % mod; } a = (a * a) % mod; b >>= 1; } return ans; }
inline void factorial(ll n, vector<ll>& a) { a.resize(n+1, 1); for(ll i=1; i<=n; i++) { a[i] = (a[i-1] * i) % MOD; } }
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

void idharDekh()
{
    ll n,k;
    cin>>n>>k;
    vin(a,n);
    bool ok = true;
    fr(i,0,n) {
        if(a[i] != a[n-i-1]){
            ok = false;
            break;
        }
    }
    if(ok){ 
       yes;
       done;
    }
    vpll vp(n);
    fr(i,0,n) vp[i] = {a[i], i};
    sort(all(vp));
    fr(i, k-1, n) {
        a.erase(a.begin() + vp[i].ss);
    }
    fr(i,0,a.size()) {
        if(a[i] != a[a.size() -i-1]) { no; done; }
    }
    yes;
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    King_T
    ll t = 1;
    cin >> t;
    while (t--)
    {
        idharDekh();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}