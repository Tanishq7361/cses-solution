///////////////////////////////////////////////////////////////////////////////////////////

// Date : 10-07-2025
// problem : Subordinates

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    vector<ll>adj[n+1];
    vector<ll>indegree(n+1,0);
    for(int i=0;i<n-1;i++){
        ll x;
        cin>>x;
        adj[i+2].push_back(x);
        indegree[x]++;
    }
    vector<ll>dist(n+1,0);
    queue<ll>q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        ll z=q.front();
        q.pop();
        for(auto w:adj[z]){
            dist[w]+=dist[z]+1;
            indegree[w]--;
            if(indegree[w]==0){
                q.push(w);
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<' ';
    }
    cout<<endl;
}