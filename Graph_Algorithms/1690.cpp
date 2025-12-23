// Date : 30-11-2025

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

const int MOD = 1e9 +7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>adj(n+1);
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        x--;y--;
        adj[x].push_back(y);
    }
    vector<vector<ll>>dp(n,vector<ll>((1ll<<(n))));
    dp[0][(1<<0)]=1;
    ll tot=(1ll<<n);
    for(int i=1;i<tot;i++){
        for(int j=0;j<n;j++){
            if(!(i&(1ll<<j))) continue;   
            if(!dp[j][i]) continue;
            for(auto k:adj[j]){
                if((1ll<<k)&i) continue;
                int final= i|(1ll<<k);
                dp[k][final]+=dp[j][i];
                dp[k][final]%=MOD;
            }
        }
    }
    cout<<dp[n-1][(1ll<<n)-1]<<endl;
}