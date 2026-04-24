///////////////////////////////////////////////////////////////////////////////////////////

// Date : 30-06-2025
// problem : Game Routes

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
const long long MOD=1e9 +7;
int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>adj(n+1);
    vll dp(n+1);
    vll indegree(n+1,0);
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        indegree[y]++;
    }
    queue<ll>q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vll topo;
    while(!q.empty()){
        ll node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto &x:adj[node]){
            indegree[x]--;
            if(indegree[x]==0){
                q.push(x);
            }
        }
    }
    dp[1]=1;
    for(auto &x:topo){
        if(dp[x]==0) continue;
        for(auto &y:adj[x]){
            dp[y]+=dp[x];
            dp[y]%=MOD;
        }
    }
    cout<<dp[n]<<endl;
}