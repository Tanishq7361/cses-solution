///////////////////////////////////////////////////////////////////////////////////////////

// Date : 24-06-2025
// problem : Range Xor Queries

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
int main()
{
    ll n,k;
    cin>>n>>k;
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vll pref(n+1,0);
    for(int i=1;i<n+1;i++){
        pref[i]^=pref[i-1]^a[i-1];
    }
    while(k--){
        ll a,b;
        cin>>a>>b;
        ll z=pref[b]^pref[a-1];
        cout<<z<<endl;
    }
}