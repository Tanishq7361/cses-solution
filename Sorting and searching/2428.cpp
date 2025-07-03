///////////////////////////////////////////////////////////////////////////////////////////

// Date : 29-06-2025
// problem : Distinct Value subarray 2

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
int main()
{
    ll n,k;
    cin>>n>>k;
    vll a(n);
    unordered_map<ll,ll>mpp;
    unordered_set<ll>st;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll low=0,high=0;
    ll ans=0;
    while(high<n){
        if(st.size()<=k){
            ans++;
            st.insert(a[high]);
            mpp[a[high]]++;
            high++;
        }
        else{
            while(st.size()>k){
                if(mpp[a[low]]==1){
                    st.erase(mpp[a[low]]);
                }
                mpp[a[low]]--;
                low++;
            }
        }
    }
    while(low<high){
        if(st.size()<=k){
            ans++;
            if(mpp[a[low]]==1){
                st.erase(mpp[a[low]]);
            }
            mpp[a[low]]--;
            low++;
        }
        else{
            while(st.size()>k){
                if(mpp[a[low]]==1){
                    st.erase(mpp[a[low]]);
                }
                mpp[a[low]]--;
                low++;
            }
        }
    }
    cout<<ans<<endl;
}