///////////////////////////////////////////////////////////////////////////////////////////

// Date : 20-06-2025
// problem : Building Teams

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

ll dfs(ll x,vector<vector<ll>>&adj,vector<bool>&vis,ll par){
    vis[x]=true;
    for(auto w:adj[x]){
        if(!vis[w]){
            //dfs(w,adj,vis);
        }
        else if(par!=w){
           // dfs();
        }
    }
}

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>adj(n+1);
    vector<bool>vis(n+1,false);
    vector<ll>par(n+1);
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        // if(dfs(i,adj,vis)){
        //     break;
        // }
    }
        
}