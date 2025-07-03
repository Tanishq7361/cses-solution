///////////////////////////////////////////////////////////////////////////////////////////

// Date : 20-06-2025
// problem : Sum of three values

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
int main()
{
    ll n,x;
    cin>>n>>x;
    vll a(n);
    multimap<ll,ll>mpp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mpp.insert({a[i],i});
    }
    for(int i=0;i<n;i++){
        ll ans=x-a[i];
        mpp.erase(mpp.find(a[i]));
        for(int j=i+1;j<n;j++){
            ll z=ans-a[j];
            if(2*z ==ans){
                if(mpp.count(z)>1){
                    mpp.erase(mpp.find(z));
                    auto it=mpp.find(z);
                    cout<<i+1<<' '<<j+1<<' '<<(*it).second+1;
                    return 0;
                }
            }
            else{
                if(mpp.count(z)>0){
                    auto it=mpp.find(z);
                    cout<<i+1<<' '<<j+1<<' '<<(*it).second+1;
                    return 0;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}