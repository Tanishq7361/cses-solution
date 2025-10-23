///////////////////////////////////////////////////////////////////////////////////////////
 
// Date : 30-08-2025
// problem : Longest Flight Route
 
#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;
 
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define ll long long
#define vll vector<long long>
#define pb push_back
#define pll pair<ll,ll>
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vll adj[n+1];
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
    }
    vll par(n+1);
    vll mx(n+1,-1);
    mx[1]=1;
    iota(par.begin(),par.end(),0);
    priority_queue<ll,vector<ll>,greater<ll>>pq;
    pq.push(1);
    while(!pq.empty()){
        auto node1=pq.top();
        pq.pop();
 
        for(auto node2 : adj[node1]){
            if(mx[node2] < mx[node1]+1){
                mx[node2]=mx[node1]+1;
                pq.push(node2);
                par[node2]=node1;
            }
        }
    }
    if(mx[n]==-1){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<mx[n]<<endl;
        ll temp=n;
        vll ans;
        ans.pb(n);
        while(temp!=par[temp]){
            temp=par[temp];
            ans.pb(temp);
        }
        reverse(ans.begin(),ans.end());
        for(auto x:ans){
            cout<<x<<' ';
        }
    }
}