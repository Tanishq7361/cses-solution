///////////////////////////////////////////////////////////////////////////////////////////
 
// problem : Longest Flight Route
 
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
#define pb push_back
#define pll pair<ll,ll>
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vll adj[n+1];
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
    }
    vll dist(n+1,-1);
    dist[1]=0;
    vll par(n+1,-1);
    queue<pair<ll,ll>>q;
    q.push({0,1});
    while(!q.empty()){
        auto [cost,node]=q.front();
        q.pop();
        for(auto &x:adj[node]){
            if(dist[x]<dist[node]+1){
                dist[x]=dist[node]+1;
                q.push({dist[x],x});
                par[x]=node;
            }
        }
    }
    if(dist[n]==-1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<ll>ans;
    ll temp=n;
    while(temp!=-1){
        ans.push_back(temp);
        temp=par[temp];
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto &x:ans){
        cout<<x<<' ';
    }
    cout<<endl;
}