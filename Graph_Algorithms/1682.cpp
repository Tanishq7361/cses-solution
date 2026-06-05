#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define vll vector<ll>

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>adj(n+1);
    vector<vector<ll>>vis(n+1,vll(2));
    vector<vector<ll>>radj(n+1);
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        radj[y].push_back(x);
    }
    function<void(ll,ll,ll)>dfs=[&](ll node, ll par, ll inx){
        if(vis[node][inx]) return;
        vis[node][inx]=true;
        for(auto &x:adj[node]){
            dfs(x,node,inx);
        }
    };
    function<void(ll,ll,ll)>dfs2=[&](ll node, ll par, ll inx){
        if(vis[node][inx]) return;
        vis[node][inx]=true;
        for(auto &x:radj[node]){
            dfs2(x,node,inx);
        }
    };
    dfs(1,-1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i][0]){
            cout<<"NO"<<endl;
            cout<<1<<' '<<i<<endl;
            return;
        }
    }
    dfs2(1,-1,1);
    for(int i=1;i<=n;i++){
        if(!vis[i][1]){
            cout<<"NO"<<endl;
            cout<<i<<' '<<1<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;

}

int main(){
    fastio;
    solve();
}