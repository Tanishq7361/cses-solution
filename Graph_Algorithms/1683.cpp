///////////////////////////////////////////////////////////////////////////////////////////

// Date : 21-07-2025
// problem : Planets and Kingdoms

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

void dfs1(ll node,stack<ll>&st,vector<bool>&vis1,vector<ll>adj[]){
    vis1[node]=1;
    for(auto it:adj[node]){
        if(!vis1[it]){
            dfs1(it,st,vis1,adj);
        }
    }
    st.push(node);
}
void dfs2(ll node,map<ll,ll>&mpp,vector<ll>adjT[],vector<bool>&vis2,ll scc){
    mpp[node]=scc;
    vis2[node]=true;
    for(auto it:adjT[node]){
        if(!vis2[it]){
            dfs2(it,mpp,adjT,vis2,scc);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<ll>adj[n+1],adjT[n+1];
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adjT[y].push_back(x);
    }
    vector<bool>vis1(n+1),vis2(n+1);
    stack<ll>st;
    for(int i=1;i<=n;i++){
        if(!vis1[i]){
            dfs1(i,st,vis1,adj);
        }
    }
    ll scc=0;
    map<ll,ll>mpp;
    while(!st.empty()){
        ll z=st.top();
        st.pop();
        if(!vis2[z]){
            scc++;
            dfs2(z,mpp,adjT,vis2,scc);
        }
    }
    cout<<scc<<endl;
    for(int i=1;i<=n;i++){
        cout<<mpp[i]<<' ';
    }
}