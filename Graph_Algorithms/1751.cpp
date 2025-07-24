///////////////////////////////////////////////////////////////////////////////////////////

// Date : 21-07-2025
// problem : Planets Cycles

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

void dfs(ll node,vector<bool>&vis,vector<ll>&temp,map<ll,ll>&mpp1,map<ll,ll>&mpp2,vll a,ll ct){
    vis[node]=true;
    mpp1[node]=ct;
    temp.push_back(node);
    if(vis[a[node]]){
        mpp2[ct]=temp.size();
    }
    else{
        dfs(a[node],vis,temp,mpp1,mpp2,a,ct);
    }
    temp.pop_back();
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    vll a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    map<ll,ll>mpp1,mpp2;
    vll temp;
    ll ct=1;
    vector<bool>vis(n+1,false);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,vis,temp,mpp1,mpp2,a,ct);
            ct++;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<mpp2[mpp1[i]]<<' ';
    }
}