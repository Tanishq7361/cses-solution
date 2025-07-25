///////////////////////////////////////////////////////////////////////////////////////////

// Date : 30-06-2025
// problem : minimizing coins

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>
int main()
{
    ll n,k;
    cin>>n>>k;
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(k==0){cout<<0<<endl;return 0;}
    vector<bool>vis(1e6+1,false);
    queue<pair<ll,ll>>pq;
    pq.push({0,0});
    while(!pq.empty()){
        ll z=pq.front().first;
        ll ct=pq.front().second;
        pq.pop();
        for(auto x:a){
            if(z+x <=k && !vis[z+x]){
                if(z+x == k){
                    cout<<ct+1<<endl;
                    return 0;
                }
                vis[z+x]=true;
                pq.push({z+x,ct+1});
            }
        }
    }
    cout<<-1<<endl;
}