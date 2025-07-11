///////////////////////////////////////////////////////////////////////////////////////////

// Date : 11-07-2025
// problem : minimizing coins

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>
const ll MOD=1e9 +7;
int main()
{
    ll n,k;
    cin>>n>>k;
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(k==0){cout<<0<<endl;return 0;}
    vector<ll>vis(1e6+1,0);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    pq.push({0,0});
    vis[0]=1;
    while(!pq.empty()){
        ll z=pq.top().first;
        ll ct=pq.top().second;
        pq.pop();
        for(auto x:a){
            if(z+x <=k){
                vis[z+x]+=vis[z];
                vis[z+x]%=MOD;
                pq.push({z+x,ct+1});
            }
        }
    }
    for(int i=0;i<k;i++){
        cout<<vis[i]<<' ';
    }
    cout<<vis[k-1]<<endl;
}