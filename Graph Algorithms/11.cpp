///////////////////////////////////////////////////////////////////////////////////////////

// Date : 27-06-2025
// problem : Flight Discount

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>adj;
    vector<ll>adj2[n+1];
    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        adj.push_back({a,b,c});
        adj2[a].push_back(b);
    }
    vector<pair<ll,ll>>dist(n+1,{LLONG_MAX,LLONG_MIN});
    dist[1]={0,0};
    for(int i=0;i<n-1;i++){
        
    }
    
}