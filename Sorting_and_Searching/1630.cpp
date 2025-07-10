///////////////////////////////////////////////////////////////////////////////////////////

// Date : 09-07-2025
// problem : Tasks and Deadlines

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    vector<pair<ll,ll>>adj(n);
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        adj[i]={x,y};
    }
    sort(adj.begin(),adj.end());
    ll sum=0;
    ll ans=0;
    for(int i=0;i<n;i++){
        sum+=adj[i].first;
        ans+=adj[i].second -sum;
    }
    cout<<ans<<endl;
}