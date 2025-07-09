///////////////////////////////////////////////////////////////////////////////////////////

// Date : 09-07-2025
// problem : 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,x;
    cin>>n>>x;
    vll a(n);
    multimap<ll,ll>mpp;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }    
    ll low=0,high=n-1;
    while(low<=high){
        ll mid=(low+high)/2;
        ll fin=x-a[mid];
        for(int i=mid+1;i<n;i++){
            mpp.insert({a[i],i});
        }
        if(x<0){
            high=mid-1;
            continue;
        }
        for(int i=mid+1;i<n;i++){
            ll ans=fin-a[i];
            mpp.erase(mpp.find(a[i]));
            for(int j=i+1;j<n;j++){
                ll z=ans-a[j];
                if(2*z ==ans){
                    if(mpp.count(z)>1){
                        mpp.erase(mpp.find(z));
                        auto it=mpp.find(z);
                        cout<<mid+1<<' '<<i+1<<' '<<j+1<<' '<<(*it).second+1;
                        return 0;
                    }
                }
                else{
                    if(mpp.count(z)>0){
                        auto it=mpp.find(z);
                        cout<<mid+1<<' '<<i+1<<' '<<j+1<<' '<<(*it).second+1;
                        return 0;
                    }
                }
            }
        }
        high=mid-1;
    }
    cout<<"IMPOSSIBLE"<<endl;
     
}