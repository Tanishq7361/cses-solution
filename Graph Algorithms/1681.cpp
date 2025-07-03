///////////////////////////////////////////////////////////////////////////////////////////

// Date : 30-06-2025
// problem : Game Routes

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
const long long MOD=1e9 +7;
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>adj(n+1);
    vll dp(n+1,0);
    vll indegree(n+1,0);
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        indegree[y]++;
    }
    queue<pair<ll,ll>>q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            dp[i]=1;
            q.push({i,dp[i]});
        }
    }
    while(!q.empty()){
        ll node=q.front().first;
        ll dist=q.front().second;
        q.pop();
        for(auto it:adj[node]){
            dp[it]+=dp[node];
            dp[it]%=MOD;
            q.push({it,dp[it]});
        }
    }
    cout<<dp[n]<<endl;
}