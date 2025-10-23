///////////////////////////////////////////////////////////////////////////////////////////

// Date : 21-10-2025
// problem : Tree Distances 2

#include <bits/stdc++.h>
using namespace std;

// .find_by_order(k)  returns iterator to kth element starting from 0;
// .order_of_key(k) returns count of elements strictly smaller than k;

#define ll long long
#define vll vector<long long>
#define pb push_back
#define pll pair<ll,ll>

const int MOD = 1e9 +7;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    vector<vll>adj(n+1);
    for(int i=0;i<n-1;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    vll tot(n+1,1),dp(n+1);
    vll ans(n+1);

    function<void(int,int)>dfs1=[&](int u, int p){
        for(auto x:adj[u]){
            if(x==p) continue;
            dfs1(x,u);
            tot[u]+=tot[x];
            dp[u]+=dp[x]+tot[x];
        }
    };
    function<void(int,int)>dfs2=[&](int u, int p){
        for(int v:adj[u]) {
            if(v==p) continue;
            ans[v]=ans[u]+(n -2*tot[v]);
            dfs2(v,u);
        }
    };
    dfs1(1,-1);
    ans[1]=dp[1];
    dfs2(1,-1);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }    
}