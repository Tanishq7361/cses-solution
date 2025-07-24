///////////////////////////////////////////////////////////////////////////////////////////

// Date : 29-06-2025
// problem : Distinct Value subarray 2

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define vll vector<long long>
int main()
{
    ll n,k;
    cin>>n>>k;
    vll a(n);
    map<ll,ll>mpp;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll low=0,high=0;
    ll ans=0;
    while(high<n){
        if(mpp.size()<k){
            mpp[a[high]]++;
        }
        else if(mpp.size()==k){
            if(mpp.find(a[high])==mpp.end()){
                while(mpp.size()==k){
                    ans+=high-low;
                    mpp[a[low]]--;
                    if(mpp[a[low]]==0){
                        mpp.erase(a[low]);
                    }
                    low++;
                }
            }
            mpp[a[high]]++;
        }
        high++;
    }
    for(int i=low;i<n;i++){
        ans+=high-i;
    }
    cout<<ans<<endl;
}