///////////////////////////////////////////////////////////////////////////////////////////

// Date : 14-02-2025
// problem : Static Range sum queries

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>
int main()
{
    ll n,q;
    cin>>n>>q;
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vll pref(n+1);
    pref[0]=0;
    for(int i=0;i<n;i++){
        pref[i+1]=a[i]+pref[i];
    }
    while(q--){
        ll a,b;
        cin>>a>>b;
        cout<<pref[b]-pref[a-1]<<endl;;
    }
}