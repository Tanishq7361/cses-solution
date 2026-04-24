#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define vll vector<ll>

void solve(){
    ll n;
    cin>>n;
    vector<ll>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<ll>>adj(n+1);
    for(int i=1;i<n;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vll ans(n+1);
    vll heavy(n+1,-1);
    vll sz(n+1);
    function<void(ll,ll)>dfs1=[&](ll node, ll par){
        sz[node]=1;
        ll mx=0;
        for(auto &child:adj[node]){
            if(child==par) continue;
            dfs1(child,node);
            sz[node]+=sz[child];
            if(sz[child]>mx){
                mx=sz[child];
                heavy[node]=child;
            }
        }
    };
    vector<map<ll,ll>*>mpp(n+1);
    function<void(ll,ll)>dfs=[&](ll node, ll par){
        for(auto &child:adj[node]){
            if(child==par || child==heavy[node]) continue;
            dfs(child,node);
        }
        if(heavy[node]!=-1){
            dfs(heavy[node],node);
            mpp[node]=mpp[heavy[node]];
        }
        else{
            mpp[node]=new map<ll,ll>();
        }
        (*mpp[node])[a[node]]++;
        for(auto &child : adj[node]){
            if(child==par || child==heavy[node]) continue;
            for(auto &x:*mpp[child]){
                (*mpp[node])[x.first]+=x.second;
            }
        }
        ans[node]=mpp[node]->size();
    };
    dfs1(1,-1);
    dfs(1,-1);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}

int main(){
    fastio;
    solve();
    return 0;
}