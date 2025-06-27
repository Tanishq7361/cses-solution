///////////////////////////////////////////////////////////////////////////////////////////

// Date : 27-06-2025
// problem : Course Schedule

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
int main()
{
    ll n,m;
    cin>>n>>m;
    vll adj[n+1];
    vll indegree(n+1,0);
    for(int i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        indegree[b]++;
        adj[a].push_back(b);
    }
    queue<ll>q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vll ans;
    while(!q.empty()){
        ll node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto x:adj[node]){
            indegree[x]--;
            if(indegree[x]==0){
                q.push(x);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(indegree[i]!=0){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}