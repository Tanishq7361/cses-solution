///////////////////////////////////////////////////////////////////////////////////////////
 
// Date : 22-06-2025
// problem : Shortest Route I
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vll vector<long long>
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(0);
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>adj[n+1];
    for(int i=0;i<m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        adj[x].emplace_back(y,z);
    }
    vector<ll>dist(n+1,LLONG_MAX);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    pq.push({0,1});
    dist[1]=0;
    while(!pq.empty()){
        ll dist1=pq.top().first;
        ll node1=pq.top().second;
        pq.pop();
        if(dist[node1]<dist1){continue;}// tle resolved
        for(auto x:adj[node1]){
            ll node2=x.first;
            ll dist2=x.second;
            if(dist1+dist2 < dist[node2]){
                pq.emplace(dist1+dist2,node2);
                dist[node2]=dist1+dist2;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<' ';
    }
}