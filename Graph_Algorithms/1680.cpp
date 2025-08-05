///////////////////////////////////////////////////////////////////////////////////////////

// Date : 31-07-2025
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
    vector<bool>vis(n+1);
    vll indeg(n+1);
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        indeg[y]++;
    }
    queue<ll>q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    vll par(n+1);
    vll dp(n+1);
    
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            q.push(i);
        }
        bool f1=false;
        while(!q.empty()){
            ll node=q.front();
            vis[node]=true;
            if(node==n){
                f1=true;
                break;
            }
            q.pop();
            for(auto x:adj[node]){
                indeg[x]--;
                if(indeg[x]==0){
                    par[x]=node;
                    q.push(x);
                }
            }
        }
        if(f1){
            break;
        }
    }
    vll ans;
    ll z=n;
    while(z!=0){
        ans.push_back(z);
        cout<<z<<endl;
        z=par[z];
    }
    reverse(ans.begin(),ans.end());
    if(ans.size()==0 || ans[0]!=1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<ans.size()<<endl;
    for(auto x:par){
        cout<<x<<' ';
    }
}