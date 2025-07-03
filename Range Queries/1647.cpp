///////////////////////////////////////////////////////////////////////////////////////////

// Date : 08-04-2025
// problem : Static range minimum queries

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
    ll z=sqrt(n)+ !(z*z==n);
    vll b(z);
    ll mn=INT_MAX;
    for(int i=0;i<n;i++){
        if(i%z==0){
            mn=INT_MAX;
        }
        mn=min(mn,a[i]);
        b[i/z]=mn;
    }
    while(q--){
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
        ll ans=INT_MAX;
        for(int j=x;j<=y;j++){
            if(j%z==0 && j+z-1<=y){
                ans=min(ans,b[j/z]);
                j+=z-1;
            }else{
                ans=min(ans,a[j]);
            }
        }
        cout<<ans<<endl;
    }
}