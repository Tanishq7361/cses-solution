///////////////////////////////////////////////////////////////////////////////////////////
 
// Date : 20-06-2025
// problem : Building Roads
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vll vector<long long>
 
void dfs(ll x,vector<vector<ll>>&adj,vector<bool>&vis){
    vis[x]=true;
    for(auto w:adj[x]){
        if(!vis[w]){
            dfs(w,adj,vis);
        }
    }
}
 
int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>adj(n+1);
    vector<bool>vis(n+1,false);
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ll ct=-1;
    vll ans;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ct++;
            ans.push_back(i);
            dfs(i,adj,vis);
        }
    }
    if(ct<=0){
        cout<<0<<endl;
    }
    else{
        cout<<ct<<endl;
        int z=ans.size();
        for(int i=0;i<z-1;i++){
            cout<<ans[i]<<' '<<ans[i+1]<<endl;
        }
    }
}