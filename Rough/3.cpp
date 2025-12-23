// created: 23.12.2025

#include <bits/stdc++.h>
using namespace std;

const long long  MOD = 1e9 + 7;
const long long  MOD1 = 998244353;

#define endl            '\n'
#define ll              long long
#define vll             vector<ll>
#define vbl             vector<bool>
#define vbll            vector<vector<bool>>
#define vvll            vector<vector<ll>>
#define vpll            vector<pair<ll,ll>>
#define pll             pair<ll, ll>
#define umll            unordered_map<ll,ll,custom_hash>
#define pb              push_back
#define bitcnt          __builtin_popcountll
#define ff              first
#define ss              second
#define yes             cout << "Yes\n"
#define no              cout << "No\n"
#define mone            cout << "-1\n"
#define done            return
#define rep(i, l, r)    for (ll i = (l); i < (r); i++)
#define repr(i, r, l)   for (ll i = (r - 1); i >= l; i--)
#define all(x)          (x).begin(), (x).end()
#define srt(x)          sort((x).begin(), (x).end())
#define rsrt(x)         sort((x).rbegin(), (x).rend())
#define rev(x)          reverse(x.begin(), x.end())
#define maxval(v)       *max_element((v).begin(), (v).end())
#define minval(v)       *min_element((v).begin(), (v).end())
#define chmax(a, b)     a=max(a, b)
#define chmin(a, b)     a=min(a, b)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(NULL)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
	for(ll i=0;i<n;i++)     \
		for (ll j=0;j<m;j++) \
			 cin>>a[i][j];          
template<class T>void vout(vector<T> &n){for(int i=0;i<int(n.size());i++){cout<<n[i]<<' ';}cout<<endl;}
template<class T>void vout(vector<vector<T>> &n){for(int i=0;i<int(n.size());i++){for(int j=0;j<int(n[i].size());j++){cout<<n[i][j]<<' ';}cout<<endl;}cout<<endl;}
#define vpout(a) for(auto x:a){cout<<x.first <<' '<<x.second<<endl;}
#define o1(a) cout<<a<<endl

// rotate(v.begin(),v.begin()+v.size()-r,v.end()); for rotating vector r times right
// rotate(v.begin(),v.begin()+r,v.end()); for rotating vector r times left

const vector<ll>dx={1,-1,0,0,1,1,-1,-1};
const vector<ll>dy={0,0,1,-1,1,-1,1,-1};
inline ll power(ll a, ll b, ll mod = MOD) { ll ans = 1; a %= mod; while(b > 0) { if(b & 1) { ans = (ans * a) % mod; } a = (a * a) % mod; b >>= 1; } return ans; }
inline bool comprev(pair<ll,ll> a, pair<ll,ll> b){if(a.ff==b.ff){return a.ss<b.ss;} else{return a.ff>b.ff;}}
inline ll modadd(ll a, ll b, ll mod = MOD) { return ((a % mod + b % mod) % mod); }
inline ll modmult(ll a, ll b, ll mod = MOD) { return ((a % mod * b % mod) % mod); }
inline ll modinv(ll a, ll mod = MOD) { return power(a, mod - 2, mod); }
inline ll msbPos(ll n){ if (n == 0) return -1; return(63 - (__builtin_clzll(n)));}
inline ll gcd(ll a, ll b) { if(b == 0) return a; return gcd(b, a % b); }
inline ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
inline ll ansXor(ll n){ return n % 4 == 0 ? n : n % 4 == 1 ? 1 : n % 4 == 2 ? n + 1 : 0; }

void solve(){
	string s;
	cin>>s;
	map<ll,ll>mpp;
	mpp[0]='r';
	mpp[1]='g';
	mpp[2]='b';
	if(s=="first"){
		ll ttt;
		cin>>ttt;
		while(ttt--){
			ll n,m;
			cin>>n>>m;
			vvll adj(n+1);
			rep(i,0,m){
				ll x,y;
				cin>>x>>y;
				adj[x].pb(y);
				adj[y].pb(x);
			}
			vll dist(n+1,-1);
			queue<ll>q;
			q.push(1);
			dist[1]=0;
			while(!q.empty()){
				ll node=q.front();
				q.pop();
				for(auto x:adj[node]){
					if(dist[x]==-1){
						dist[x]=dist[node]+1;
						q.push(x);
					}
				}
			}
			string ans="";
			rep(i,1,n+1){
				ll z=dist[i]+3;
				z%=3;
				ans.pb(mpp[z]);
			}
			o1(ans);
		}
	}
	else{
		ll ttt;
		cin>>ttt;
		while(ttt--){
			ll q;
			cin>>q;
			while(q--){
				ll w;
				cin>>w;
				string s1;
				cin>>s1;
				bool f1=false,f2=false,f3=false;
				ll x1=-1,x2=-1,x3=-1;
				repr(i,w,0){
					if(s[i]=='r'){
						f1=true;
						x1=i;
					}
					if(s[i]=='g'){
						f2=true;
						x2=i;
					}
					if(s[i]=='b'){
						f3=true;
						x3=i;
					}
				}
				if((f1 && !f2 && !f3) || (!f1 && f2 && !f3) || (!f1 && !f2 && f3)){
					o1(1);
				}
				else{
					if(!f3){
						o1(max(1ll,x2+1));
					}
					else if(!f2){
						o1(max(1ll,x1+1));
					}
					else if(!f1){
						o1(max(1ll,x3+1));
					}
					else{
						o1(max(1ll,x1+1));
					}

				}

			}
		}
	}
}


int main(){
	fastio;
	// cout << fixed << setprecision(15);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int tt = 1;
	cin >> tt;
	for(int i=1;i<=tt;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}



// g++ -std=c++17 -O2 practise.cpp -o practise
// ./practise < input.txt > output.txt