///////////////////////////////////////////////////////////////////////////////////////////

// Date : 16-08-2025
// problem : Flight Discount

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
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<vector<ll>>dp(n+1,vll(2,1e15));
    priority_queue<pair<pair<ll,ll>,bool>,vector<pair<pair<ll,ll>,bool>>,greater<pair<pair<ll,ll>,bool>>>pq;
    pq.push({{0,1},0});
    dp[1][0]=0;
    dp[1][1]=0;
    while(!pq.empty()){
        ll dist=pq.top().first.first;
        ll node=pq.top().first.second;
        bool code=pq.top().second;
        pq.pop();
        if (dist > dp[node][code]) continue;// this minimizes operations
        for(auto x : adj[node]){
            ll node2=x.first;
            ll cost=x.second;
            if(dp[node2][code]>dist+cost){
                dp[node2][code]=dist+cost;
                pq.push({{dist+cost,node2},code});
            }
            if(!code && dp[node2][1]>dist+ cost/2){
                dp[node2][1]=dist+ cost/2;
                pq.push({{dist+ cost/2,node2},true});
            }
        }
    }
    cout<<dp[n][1]<<endl;

}