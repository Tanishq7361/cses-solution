///////////////////////////////////////////////////////////////////////////////////////////
 
// Date : 22-06-2025
// problem : Shortest Route I
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vll vector<long long>
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>adj[n+1];
    for(int i=0;i<m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
    }
    vector<bool>vis(n+1,false);
    vector<ll>dist(n+1,LLONG_MAX);
    
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    pq.push({0,1});
    dist[1]=0;
    vis[1]=true;
    while(!pq.empty()){
        ll dist1=pq.top().first;
        ll node1=pq.top().second;
        pq.pop();
        for(auto x:adj[node1]){
            ll node2=x.first;
            ll dist2=x.second;
            if(!vis[node2]){
                pq.push({dist1+dist2,node2});
                vis[node2]=true;
                dist[node2]=dist1+dist2;
            }
            else if(vis[node2] && (dist1+dist2 < dist[node2])){
                pq.push({dist1+dist2,node2});
                dist[node2]=dist1+dist2;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<' ';
    }
}