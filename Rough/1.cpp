/*
    Created : 28.03.2025  16:54:54
*/

#include <bits/stdc++.h>
using namespace std;

#define King ios_base::sync_with_stdio(0);
#define T cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long
#define stc static_cast
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define pll pair<long long, long long>
#define mll map<long long, long long>
#define umll unordered_map<long long, long long>
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
#define fr(i, l, r) for(ll i=(l); i<(r); i++)
#define frr(i, r, l) for(ll i=(r-1); i>=l; i--)
#define str(s) \
    string s;    \
    cin >> s
#define in(n) ll n;cin>>n 
#define inn(n,k) ll n,k;cin>>n>>k 
#define vin(a, n)        \
    vll a(n);              \
    for(ll i = 0; i < n; i++) \
    cin >> a[i];
#define vout(a) for(auto x : a) { cout << x << ' '; } cout << '\n';
#define out(a) cout << a << '\n';
#define sze(x) ll((x).size())
#define all(x) (x).begin(), (x).end()
#define srt(x) sort((x).begin(), (x).end())
#define rsrt(x) sort((x).rbegin(), (x).rend())
#define rev(x) reverse(x.begin(),x.end())
#define maxval(v) *max_element((v).begin(), (v).end())
#define minval(v) *min_element((v).begin(), (v).end())
#define maxid(v) max_element((v).begin(), (v).end()) - ((v).begin())
#define minid(v) min_element((v).begin(), (v).end()) - ((v).begin())
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const long long INF = 1e18 + 9;
const int MOD = 1e9 + 7;
const long long MOD1 = 998244353;

inline ll gcd(ll a, ll b) { while(b) { a %= b; swap(a, b); } return a; }
inline ll lcm(ll a, ll b) { return ((a / gcd(a, b)) * b); }
inline bool isPrime(ll n) {
    if(n <= 1) return false; if(n <= 3) return true; if(n % 2 == 0 || n % 3 == 0) return false;
    for(ll i=5; i*i<=n; i+=6) { if(n % i == 0 || n % (i+2) == 0) return false; } return true;
}
void prime(ll n, vector<bool>& ispr) {
    ispr.resize(n+1, true); ispr[0] = ispr[1] = false;
    for(ll i=2; i*i<=n; i++) { if(ispr[i]) { for(ll j=i*i; j<=n; j+=i) { ispr[j] = false; } } }
}
void prime(ll n, vector<ll>& pr) {
    vector<bool> ispr; prime(n, ispr); for(ll i=2; i<=n; i++) { if(ispr[i]) { pr.push_back(i); } }
}
inline ll power(ll a, ll b, ll mod = MOD) {
    ll ans = 1; a %= mod; while(b > 0) { if(b & 1) { ans = (ans * a) % mod; } a = (a * a) % mod; b >>= 1; } return ans;
}
inline void factorial(ll n, vector<ll>& a) { a.resize(n+1, 1); for(ll i=1; i<=n; i++) { a[i] = (a[i-1] * i) % MOD; } }
inline bool isPowOfTwo(ll n) { return ((n > 0) && !(n & (n-1))); }
inline bool isPerfectSq(ll n) { if(n < 0) return false; ll sr = static_cast<ll>(sqrt(n)); return (sr*sr == n); }
inline bool compbyss(pair<ll, ll> a, pair<ll, ll> b) { return a.second < b.second; }
inline bool comprev(pair<ll,ll> a, pair<ll,ll> b){if(a.ff==b.ff){return a.ss<b.ss;} else{return a.ff>b.ff;}}
inline ll modadd(ll a, ll b, ll mod = MOD) { return ((a % mod + b % mod) % mod); }
inline ll modmult(ll a, ll b, ll mod = MOD) { return ((a % mod * b % mod) % mod); }
inline ll modinv(ll a, ll mod = MOD) { return power(a, mod-2, mod); }
inline ll moddiv(ll a, ll b, ll mod = MOD) { return modmult(a, modinv(b, mod), mod); }
inline ll msbPos(ll n) { if(n == 0) { return -1; } return (63 - (__builtin_clzll(n))); }
inline ll getBit(ll n, ll pos) { return ((n >> pos) & 1); }
inline ll setBit(ll n, ll pos) { return (n | (1 << pos)); }
inline ll clearBit(ll n, ll pos) { return (n & (~(1 << pos))); }
inline ll toggleBit(ll n, ll pos) { return (n ^ (1 << pos)); }

// =-=-=-=-=-=-=-=-=-=-=-=-=-code starts here -=-=-=-=-=-=-=-=-=-=-=-=-= //

ll cow(ll x,vll a){
    ll m=a.size();
    ll ans2=1;
    ll y=a[0];
    fr(i,1,m){
        if(a[i]-y>=x){
            ans2++;
            y=a[i];
        }
    }
    return ans2;
}

void idharDekh()
{
    inn(n,k);
    vin(a,n);
    srt(a);
    ll ans=-1;
    ll low=0,high=1e9+7;
    ll mid;
   // cout<<cow(1,a)<<endl;
    while(low<=high){
        mid=(low+high)/2;
        if(cow(mid,a)<k){
            high=mid-1;
        }
        else{
            ans=mid;
            low=mid+1;
        }
    }
    cout<<ans<<endl;
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    King T
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