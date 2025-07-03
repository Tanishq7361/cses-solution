///////////////////////////////////////////////////////////////////////////////////////////

// Date : 27-06-2025
// problem : Flight Discount

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>adj2[n+1];
    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        adj2[a].push_back({b,c});
    }
    vector<pair<ll,ll>>dist(n+1,{1e15,-2});
    dist[1]={0,0};
    priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>>pq;
    pq.push({0,{0,1}});
    while(!pq.empty()){
        auto it=pq.top();
        ll node1=it.second.second;
        ll mx=it.second.first;
        ll dist1=it.first;
        pq.pop();
        for(auto x:adj2[node1]){
            ll node2=x.first;
            ll dist2=x.second;
            ll mx2=max(mx,dist2);
            if(dist1+dist2 - (mx2/2) <  (dist[node2].first -  (dist[node2].second)/2)){
                dist[node2]={dist1+dist2,mx2};
                pq.push({dist1+dist2,{mx2,node2}});
            }
            else if(dist1+dist2 - (mx2/2) == (dist[node2].first -  (dist[node2].second)/2)){
                if(mx2 < dist[node2].second){
                    dist[node2]={dist1+dist2,mx2};
                    pq.push({dist1+dist2,{mx2,node2}});
                }
            }
        }
    }
    cout<<dist[n].first - (dist[n].second+1)/2<<endl;
}