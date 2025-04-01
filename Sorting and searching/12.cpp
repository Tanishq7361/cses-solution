///////////////////////////////////////////////////////////////////////////////////////////

// Date : 31-03-2025
// problem : Collecting Numbers

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>
int main()
{
    ll n,m;
    cin>>n>>m;
    vll a(n);
    map<ll,ll>mpp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mpp[a[i]]=i;
    }
    ll ans=1;
    ll prev=-1;
    for(auto i:mpp){
        if(i.second<prev){
            ans++;
        }
        prev=i.second;
    }
    while(m--){
        ll x,y;
        cin>>x>>y;
        x--,y--;
        

    }
}