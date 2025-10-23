///////////////////////////////////////////////////////////////////////////////////////////

// Date : 09-09-2025
// problem : Tree Matching

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// .find_by_order(k)  returns iterator to kth element starting from 0;
// .order_of_key(k) returns count of elements strictly smaller than k;

#define ll long long
#define vll vector<long long>
#define pb push_back
#define pll pair<ll,ll>

const int MOD = 1e9 +7;

void dfs(ll node, ll par, vector<vector<ll>>&adj,vector<vector<ll>>&dp){
    vll temp;
    for(auto x:adj[node]){
        if(x==par){continue;}
        dfs(x,node,adj,dp);
        temp.pb(x);
        dp[node][0]+=max(dp[x][0],dp[x][1]);
    }
    for(auto x:temp) {
        dp[node][1]=max(dp[node][1],dp[node][0] - max(dp[x][0], dp[x][1]) + dp[x][0] + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    vector<vector<ll>>adj(n+1);
    vector<vector<ll>>dp(n+1,vll(2));
    for(int i=0;i<n-1;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1,-1,adj,dp);
    cout<<max(dp[1][0],dp[1][1])<<'\n';
}

// maxm n/2 can be possible so answer is less than n/2
