///////////////////////////////////////////////////////////////////////////////////////////

// Date : 09-09-2025
// problem : Tree Diameter

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

void dfs(ll node, ll par, vector<vector<ll>>&adj, vll&dist,ll&mx){
    vll temp;
    for(auto x:adj[node]){
        if(x==par){continue;}
        dfs(x,node,adj,dist,mx);
        dist[node]=max(dist[node],dist[x]+1);
        temp.pb(dist[x]);
    }
    if(temp.size()==0){
        return;
    }
    else if(temp.size()==1){
        mx=max(mx,1+temp[0]);
    }
    else if(temp.size()==2){
        mx=max(mx,2+temp[0]+temp[1]);
    }
    else{
        sort(temp.rbegin(),temp.rend());
        mx=max(mx,2+temp[0]+temp[1]);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // !! first method is doing bfs/dfs 2 times !!
    // in first bfs find farthest node 
    // in second bfs find farthest from farthest
    // this will give diameter

    ll n;
    cin>>n;
    vector<vector<ll>>adj(n+1);
    for(int i=0;i<n-1;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vll dist(n+1);
    ll mx=0;
    dfs(1,-1,adj,dist,mx);
    cout<<mx<<'\n';
}