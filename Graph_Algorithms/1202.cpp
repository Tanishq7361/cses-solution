///////////////////////////////////////////////////////////////////////////////////////////

// Date : 30-08-2025
// problem : Investigation

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define vll vector<long long>
#define pb push_back
#define pll pair<ll,ll>

const int MOD = 1e9 +7;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<pll>adj[n+1];
    for(int i=0;i<m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        adj[x].pb({y,z});
    }
    // price,node,total flights
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;

    vll dist(n+1,LLONG_MAX);
    vll dp(n+1);
    vll mx(n+1,LLONG_MIN);
    vll mn(n+1,LLONG_MAX);

    dist[1]=0;
    dp[1]=1;
    mn[1]=0;
    mx[1]=0;

    pq.push({0,1});

    while(!pq.empty()){
        auto [dist1,node1]=pq.top();
        pq.pop();
        if(dist1 != dist[node1]) continue;

        for(auto [node2,cost]:adj[node1]){

            if(dist[node1]+cost < dist[node2]){
                mx[node2]=mx[node1]+1;
                mn[node2]=mn[node1]+1;
                dp[node2]=dp[node1];
                dist[node2]=dist[node1]+cost;
                pq.push({dist[node2],node2});
            }
            else if(dist[node1]+cost == dist[node2]){
                mx[node2]=max(mx[node2],mx[node1]+1);
                mn[node2]=min(mn[node2],mn[node1]+1);
                dp[node2]+=dp[node1];
                dp[node2]%=MOD;
            }
        }
    }
    cout<<dist[n]<<' '<<dp[n]<<' '<<mn[n]<<' '<<mx[n]<<endl;
}