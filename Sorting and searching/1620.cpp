///////////////////////////////////////////////////////////////////////////////////////////

// Date : 02-07-2025
// problem : Factory Machines

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
    ll low=1,high=1e18;
    ll ans;
    while(low<=high){
        ll mid=(low+high)/2;
        ll z=0;
        for(int i=0;i<n;i++){
            z+=mid/a[i];
            if(z>k){
                break;
            }
        }
        if(z>=k){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<ans<<endl;
}