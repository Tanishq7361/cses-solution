///////////////////////////////////////////////////////////////////////////////////////////

// Date : 16-08-2025
// problem : Flight Routes

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define vll vector<long long>

// djikstra with max priority_queue

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,m,k;
    cin>>n>>m>>k;
    vector<pair<ll,ll>>adj[n+1];
    vector<ll> ans;
    for(int i=0;i<m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    vector<int>cnt(n+1);
    pq.push({0,1});
    while(!pq.empty()){
        ll city=pq.top().second;
        ll dist1=pq.top().first;
        pq.pop();
        cnt[city]++;
        if(cnt[city]>k) continue;
        if(city==n){
            ans.push_back(dist1);
        }
        for(auto x:adj[city]){
            pq.push({dist1+x.second,x.first});
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<k;i++){
        cout<<ans[i]<<' ';
    }

}