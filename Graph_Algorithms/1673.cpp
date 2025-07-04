///////////////////////////////////////////////////////////////////////////////////////////

// Date : 26-06-2025
// problem : High Score

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>adj;
    vector<ll>adj2[n+1];
    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        adj.push_back({a,b,c});
        adj2[b].push_back(a);
    }
    vector<ll>dist(n+1,LLONG_MIN);
    dist[1]=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            if(dist[adj[j][0]]==LLONG_MIN){continue;}
            if(dist[adj[j][1]]<dist[adj[j][0]]+adj[j][2]){
                dist[adj[j][1]]=dist[adj[j][0]]+adj[j][2];
            }
        }
    }
    vll dist2(dist.begin(),dist.end());
    for(int j=0;j<m;j++){
        if(dist[adj[j][0]]==LLONG_MIN){continue;}
        if(dist[adj[j][1]]<dist[adj[j][0]]+adj[j][2]){
            dist[adj[j][1]]=dist[adj[j][0]]+adj[j][2];
        }
    }
    if(dist[n]!=dist2[n]){
        cout<<-1<<endl;
        return 0;
    }
    vector<bool>vis(n+1,false);
    queue<ll>q;
    q.push(n);
    vis[n]=true;
    while(!q.empty()){
        ll z=q.front();
        q.pop();
        for(auto x:adj2[z]){
            if(vis[x]){continue;}
            if(dist[x]!=dist2[x]){
                cout<<-1<<endl;
                return 0;
            }
            vis[x]=true;
            q.push(x);
        }
    }
    cout<<dist[n]<<endl;    
}