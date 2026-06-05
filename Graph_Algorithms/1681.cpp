#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define vll vector<ll>

const int MOD=1e9 +7;

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>adj(n+1);
    vll dp(n+1);
    dp[1]=1;
    vll indeg(n+1);
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        indeg[y]++;
    }
    queue<ll>q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0) q.push(i);
    }
    while(!q.empty()){
        ll node=q.front();
        q.pop();
        for(auto &x:adj[node]){
            indeg[x]--;
            dp[x]+=dp[node];
            dp[x]%=MOD;
            if(indeg[x]==0) q.push(x);
        }
    }
    cout<<dp[n]<<endl;
}

int main(){
    fastio;
    solve();
}