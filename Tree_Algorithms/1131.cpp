// Date : 19-12-2025

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MOD = 1e9 +7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<vector<ll>>adj(n+1);
    for(int i=1;i<n;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<ll>dp(n+1);
    vector<ll>up(n+1);
    vector<ll>down(n+1);
    
    function<void(ll,ll)>dfs=[&](ll node, ll par){
        for(auto x:adj[node]){
            if(x==par) continue;
            dfs(x,node);
            down[node]=max(down[node],down[x]+1);
        }
    };
    function<void(ll,ll)>dfs2=[&](ll node, ll par){
        for(auto x:adj[node]){
            if(x==par) continue;
            dfs(x,node);
            down[node]=max(down[node],down[x]+1);
        }
    };
    dfs(1,0);
    dfs2(1,0);
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<' ';
    }
}

