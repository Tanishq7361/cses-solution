// Date : 21-12-2025
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int MOD = 1e9 +7;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>>adj(n+1);
    vector<int>up(n+1),down(n+1);
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<vector<int>>dist(n+1,vector<int>(3));
    function<void(ll,ll,ll)>bfs=[&](ll node, ll par, ll inx){
        queue<ll>q;
        q.push(node);
        vector<bool>vis(n+1);
        vis[node]=true;
        while(!q.empty()){
            ll garb=q.front();
            q.pop();
            for(auto x:adj[garb]){
                if(!vis[x]){
                    q.push(x);
                    vis[x]=true;
                    dist[x][inx]=dist[garb][inx]+1;
                }
            }
        }
    };
    bfs(1,-1,0);
    ll mx=0;
    ll nodeA=1;
    for(int i=1;i<=n;i++){
        if(dist[i][0]>mx){
            mx=dist[i][0];
            nodeA=i;
        }
    }
    bfs(nodeA,-1,1);
    mx=0;
    ll nodeB=1;
    for(int i=1;i<=n;i++){
        if(dist[i][1]>mx){
            mx=dist[i][1];
            nodeB=i;
        }
    }
    bfs(nodeB,-1,2);
    for(int i=1;i<=n;i++){
        cout<<max(dist[i][1],dist[i][2])<<' ';
    }
 
}