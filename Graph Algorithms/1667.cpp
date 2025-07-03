///////////////////////////////////////////////////////////////////////////////////////////

// Date : 20-06-2025
// problem : Message Route

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll>adj[n+1];
    vector<bool>vis(n+1,false);
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<ll>q;
    vll par(n+1,0);
    q.push(1);
    bool f1=false;
    while(!q.empty()){
        ll x=q.front();
        q.pop();
        if(x==n){
            f1=true;
            break;
        }
        for(auto w:adj[x]){
            if(!vis[w]){
                q.push(w);
                par[w]=x;
                vis[w]=true;
            }
        }
    }
    if(!f1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    ll ct=1;
    ll z=n;
    vll ans;
    while(z!=1){
        ans.push_back(z);
        ct++;
        z=par[z];
    }
    ans.push_back(1);
    reverse(ans.begin(),ans.end());
    cout<<ct<<endl;
    for(auto p:ans){
        cout<<p<<' ';
    }
    cout<<endl;
}