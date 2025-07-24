///////////////////////////////////////////////////////////////////////////////////////////

// Date : 21-07-2025
// problem : Cycle Finding

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
#define ff first
#define ss second
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> adj[n+1];
    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vll dist(n+1,LLONG_MAX);
    vll par(n+1);
    for(int i=0;i<n;i++){
        for(int j=1;j<n+1;j++){
            if(dist[j]==LLONG_MAX){dist[j]=0;par[j]=j;}
            for(auto x:adj[j]){
                ll node=x.ff;
                ll cost=x.ss;
                if(dist[node]>dist[j]+cost){
                    dist[node]=dist[j]+cost;
                    par[node]=j;
                }
            }
        }
    }
    ll noder=-1;
    for(int j=1;j<n+1;j++){
        if(dist[j]==LLONG_MAX){dist[j]=0;par[j]=j;}
        for(auto x:adj[j]){
            ll node=x.ff;
            ll cost=x.ss;
            if(dist[node]>dist[j]+cost){
                noder=node;
                par[node]=j;
            }
        }
    }
    if(noder==-1){cout<<"NO"<<endl;return 0;}
    cout<<"YES"<<endl;
    vll ans;
    vector<bool>vis(n+1,false);
    ll temp=noder;
    while(vis[temp]==false){
        ans.push_back(temp);
        vis[temp]=true;
        temp=par[temp];
    }
    ans.push_back(temp);
    reverse(ans.begin(),ans.end());
    int z=ans.size();
    for(int i=z-1;i>=0;i--){
        if(ans[i]==ans[0]){
            break;
        }
        ans.pop_back();
    }
    for(auto it:ans){
        cout<<it<<' ';
    }
}