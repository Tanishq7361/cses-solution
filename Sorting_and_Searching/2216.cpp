///////////////////////////////////////////////////////////////////////////////////////////

// Date : 31-03-2025
// problem : collecting Numbers

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>
int main()
{
    ll n;
    cin>>n;
    vll a(n);
    map<ll,ll>mpp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mpp[a[i]]=i;
    }
    ll prev=-1;
    ll ans=1;
    for(auto i:mpp){
        if(i.second<prev){
            ans++;
        }
        prev=i.second;
    }
    cout<<ans<<endl;
    return 0;
}