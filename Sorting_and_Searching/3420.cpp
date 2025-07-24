///////////////////////////////////////////////////////////////////////////////////////////

// Date : 21-07-2025
// problem : Distinct Values Subarrays

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    map<ll,ll>mpp;
    ll low=0,high=0;
    vll pref(n,0);
    while(high<n){
        mpp[a[high]]++;
        if(mpp.size()!=high-low+1){
            while(mpp[a[high]]!=1){
                pref[low]=high-low;
                mpp[a[low]]--;
                if(mpp[a[low]]==0){
                    mpp.erase(a[low]);
                }
                low++;
            }
        }
        high++;
    }
    while(low<n){
        pref[low]=high-low;
        low++;
    }
    for(int i=1;i<n;i++){
        pref[i]+=pref[i-1];
    }
    cout<<pref[n-1]<<endl;
}