///////////////////////////////////////////////////////////////////////////////////////////

// Date : 02-07-2025
// problem : Missing Coin sum

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
int main()
{
    ll n;
    cin>>n;
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    ll ans=1;
    for(int i=0;i<n;i++){
        if(ans<a[i]){
            cout<<ans<<endl;
            return 0;
        }
        else{
            ans+=a[i];
        }
    }
    cout<<ans<<endl;
}