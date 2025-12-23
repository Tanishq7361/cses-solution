// Date : 23-12-2025

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MOD = 1e9 +7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<ll>cnt(n+1);
    vector<vector<ll>>adj(n+1);
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    function<void(ll,ll)>dfs=[&](ll node, ll par){
        for(auto x:adj[node]){

        }
    };
    dfs(1,0);
    for(int i=2;i<=n;i++){

    }
}