// created: 06.02.2026

#include <bits/stdc++.h>
using namespace std;

const long long MAXX=1e18 +13;
const long long MOD=1e9 +7;
const long long MOD1=998244353;

#define endl            '\n'
#define ll              long long
#define vll             vector<ll>
#define vvll            vector<vector<ll>>
#define vpll            vector<pair<ll,ll>>
#define pll             pair<ll,ll>
#define pb              push_back
#define bitcnt          __builtin_popcountll
#define ff              first
#define ss              second
#define yes             cout<<"Yes\n"
#define no              cout<<"No\n"
#define mone            cout<<-1<<endl
#define done            return
#define rep(i,l,r)      for(ll i=(l);i<(r);i++)
#define repr(i,r,l)     for(ll i=(r-1);i>=l;i--)
#define all(x)          (x).begin(),(x).end()
#define srt(x)          sort((x).begin(),(x).end())
#define rev(x)          reverse(x.begin(),x.end())
#define maxvl(v)        *max_element((v).begin(),(v).end())
#define minvl(v)        *min_element((v).begin(),(v).end())
#define fastio          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define flush           cout.flush()
#define deb(x)          cerr<<(#x)<<" is "<<(x)<<endl
#define vin(T,a,n)      vector<T>a(n); rep(i,0,n) cin>>a[i];
#define vvin(T,a,n,m)   vector<vector<T>>a(n,vector<T>(m)); rep(i,0,n) rep(j,0,m) cin>>a[i][j];
inline  bool            compar(pair<ll,ll>a,pair<ll,ll>b){if(a.ff==b.ff){return a.ss<b.ss;} else{return a.ff>b.ff;}}
inline  bool            fastprime(ll n){return n>1 && (n<=3 || (n%2 && n%3 && [&](){for(ll i=5;i*i<=n;i+=6) if(n%i==0||n%(i+2)==0) return false; return true;}()));}
inline  ll              powerfn(ll a,ll b,ll mod=MOD){ll ans=1; a%=mod; while(b>0){ if(b&1){ans=(ans*a)%mod;} a=(a*a)%mod; b>>=1;} return ans;}
inline  ll              modsum(ll a,ll b,ll mod=MOD){return ((a%mod + b%mod)%mod);}
inline  ll              modmul(ll a,ll b,ll mod=MOD){return ((a%mod * b%mod)%mod);}
inline  ll              modinv(ll a,ll mod=MOD){return powerfn(a,mod-2,mod);}
inline  ll              msbpos(ll n){if(n==0) return -1; return (63-(__builtin_clzll(n)));}
inline  ll              gcd(ll a,ll b){if(b==0) return a; return gcd(b,a%b);}
inline  ll              lcm(ll a,ll b){return (a/gcd(a,b) *b);}
inline  ll              nCr(ll n,ll r){if(r>n) return 0; if(r>n-r) r=n-r; ll res=1; for(ll i=1;i<=r;i++) res=res*(n-i+1)/i; return res;}
inline  ll              ansxor(ll n){return n%4==0 ? n : n%4==1 ? 1 : n%4==2 ? n+1 : 0;}
const   vector<ll>dx    ={1,0,-1,0,1,1,-1,-1};
const   vector<ll>dy    ={0,1,0,-1,1,-1,1,-1};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>void vout(vector<T>&n){for(auto &x:n){cout<<x<<' ';}cout<<endl;}
template<class T>void vout(vector<vector<T>>&n){for(auto &x:n){for(auto &y:x){cout<<y<<' ';}cout<<endl;}}
#define vpout(a) for(auto x:a){cout<<x.first<<' '<<x.second<<endl;}
#define o1(a) cout<<a<<endl


void solve(){
    ll n;
    cin>>n;
    vin(ll,a,n);
}


int main(){
    fastio;
    // cout<<fixed<<setprecision(15);
    int tt=1;
    cin>>tt;
    for(int i=1;i<=tt;i++){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}


// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// g++ -std=c++17 -O2 practise.cpp -o practise
// ./practise < input.txt > output.txt