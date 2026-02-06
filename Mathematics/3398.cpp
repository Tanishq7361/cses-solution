// created: 18.01.2026
 
#include <bits/stdc++.h>
using namespace std;
const long long MOD=1e9 +7;
#define ll              long long
#define vll             vector<ll>
#define pb              push_back
#define ff              first
#define ss              second
#define chmax(a,b)      a=max(a,b)
inline  ll              powerfn(ll a,ll b,ll mod=MOD){ll ans=1; a%=mod; while(b>0){ if(b&1){ans=(ans*a)%mod;} a=(a*a)%mod; b>>=1;} return ans;}
inline  ll              modmul(ll a,ll b,ll mod=MOD){return ((a%mod * b%mod)%mod);}
inline  ll              gcd(ll a,ll b){if(b==0) return a; return gcd(b,a%b);}
inline  ll              lcm(ll a,ll b){return ((a/gcd(a,b) *b)%MOD);}
 
 
void sievechck(ll mxn, vll&nprime, vll &req){
    //non prime malse
    nprime.resize(mxn+1);
    for(ll i=4;i<mxn;i=i+2) nprime[i]=1;
    for(ll i=3;i*i<mxn;i=i+2){
        if(nprime[i]==0){
            for(ll j=i*i;j<mxn;j=j+i+i){
                //bahu mast vastu kari
                nprime[j]=1;
            }
        }
    }
    for(int i=2;i<=mxn;i++){
        if(nprime[i]==0){
            req.pb(i);
        }
    }
}
 
 
void solve(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    vector<int>adj(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
        adj[i+1]=a[i];
    }
    vector<bool>vis(n+1);
    function<ll(ll)>dfs=[&](ll node)->ll {
        if(vis[node]){
            return 0;
        }
        vis[node]=true;
        return dfs(adj[node])+1;
    };
    ll ans=1;
    unordered_map<ll,ll>mpp;
    vll all;
    vll prime;
    sievechck(n+1,all,prime);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ll tot=dfs(i);
            for(auto &x:prime){
                ll ct=0;
                while(tot%x==0){
                    ct++;
                    tot/=x;
                }
                if(ct){
                    chmax(mpp[x],ct);
                }
                if(tot==1){
                    break;
                }
            }
        }
    }
    for(auto &x:mpp){
        ans=modmul(ans,powerfn(x.ff,x.ss));
    }
    cout<<ans<<endl;
}
 
int main(){
    solve();
    return 0;
}