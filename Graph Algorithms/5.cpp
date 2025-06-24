///////////////////////////////////////////////////////////////////////////////////////////

// Date : 20-06-2025
// problem : Building Teams

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

bool dfs(vector<vector<ll>>&adj,vector<int>&vis,int nod,int prev){
    vis[nod]=prev;
    for(auto x:adj[nod]){
        if(vis[x]==-1){
            bool ans2=dfs(adj,vis,x,!prev);
            if(!ans2){
                return false;
            }
        }
        else{
            if(vis[x]==prev){
              return false;
            }
        }
    }
    return true;
}

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>adj(n+1);
    vector<int>vis(n+1,-1);
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==-1){
            bool ans=dfs(adj,vis,i,1);
            if(!ans){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<vis[i]+1<<' ';
    }
}