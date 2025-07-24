///////////////////////////////////////////////////////////////////////////////////////////

// Date : 21-07-2025
// problem : Longest Flight Route

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vll adj[n+1];
    vll par(n+1);
    par[1]=1;
    vll indegree(n+1);
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        indegree[y]++;
    }
    queue<pair<ll,ll>>q;
    vll vis(n+1);
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push({i,1});
            par[i]=i;
        }
    }
    while(!q.empty()){
        ll node=q.front().second;
        ll dist=q.front().first;
        q.pop();
        for(auto x:adj[node]){
            indegree[x]--;
            if(indegree[x]==0){
                par[x]=node;
                q.push({dist+1,x});
            }
        }
    }
    vll ans;
    vector<bool>vis2(n+1);
    ll temp=n;
    while(temp!=1){
        if(vis2[temp]){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
        ans.push_back(temp);
        vis2[temp]=true;
        temp=par[temp];

    }
    ans.push_back(1);
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto x:ans){
        cout<<x<<' ';
    }
}