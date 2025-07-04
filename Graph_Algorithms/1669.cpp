///////////////////////////////////////////////////////////////////////////////////////////

// Date : 22-06-2025
// problem : Round Trip

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

ll dfs(vector<vector<ll>>&adj,vector<bool>&vis,int nod,int prev,vector<ll>&par){
    vis[nod]=true;
    par[nod]=prev;
    ll ans=-1;
    for(auto x:adj[nod]){
        if(!vis[x]){
            ans=dfs(adj,vis,x,nod,par);
            if(ans!=-1){
                return ans;
            }
        }
        else if(vis[x] && x!=prev){
            par[x]=nod;
            return x;
        }
    }
    return ans;
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
    ll st=-1;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ll ans2=dfs(adj,vis,i,-1,par);
            if(ans2!=-1){
                st=ans2;
                break;
            }
        }
    }
    if(st==-1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    ll ct=st;
    vll ans3;
    ans3.push_back(st);
    st=par[st];
    while(st!=ct){
        ans3.push_back(st);
        st=par[st];
    }
    ans3.push_back(st);
    cout<<ans3.size()<<endl;
    for(auto w:ans3){
        cout<<w<<' ';
    }
    cout<<endl;
}