///////////////////////////////////////////////////////////////////////////////////////////

// Date : 18-03-2025
// problem : Stick Length

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>
int main()
{
    ll n;
    cin>>n;
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vll pref(n+1,0);
    for(int i=1;i<n+1;i++){
        pref[i]=pref[i-1]+a[i-1];
    }
    ll ans=100000000000000000;
    for(int i=0;i<n;i++){
        ll z=i*a[i];
        z-=pref[i];
        z-=(n-1-i)*a[i];
        z+=pref[n]-pref[i+1];
        ans=min(ans,z);
        //cout<<z<<endl;
    }
    cout<<ans<<endl;
}