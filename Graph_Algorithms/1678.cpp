///////////////////////////////////////////////////////////////////////////////////////////

// Date : 30-08-2025
// problem : Round Trip 2

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


bool dfs(int node,int ppar,int abss,vector<vll>&adj,vll&vis,vll&par,vll&ans){
    
    
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<vll> adj(n+1);
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
    }
    vll vis(n+1),par(n+1),ans;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i,-1,i,adj,vis,par,ans);
        }
    }

}