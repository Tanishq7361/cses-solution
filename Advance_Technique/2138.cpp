// Date : 21-01-2026

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 +7;
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}


int main(){
    fast();
    ll n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    vector<ll>subs(n+1,1);
    vector<bool>vis(n+1);
    function<void(ll)>dfs=[&](ll node){
        vis[node]=true;
        for(auto &x:adj[node]){
            if(!vis[x]){
                dfs(x);
            }
            subs[node]+=subs[x];
        }
    };
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
        cout<<subs[i]<<' ';
    }
    cout<<endl;
}