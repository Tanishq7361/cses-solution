///////////////////////////////////////////////////////////////////////////////////////////

// Date : 09-07-2025
// problem : Subarray Sums II

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vll a(n);
    ll sum=0;
    ll ans=0;
    map<ll,ll>mpp;
    mpp[0]++;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        ans+=mpp[sum-k];
        mpp[sum]++;
    }
    cout<<ans<<endl;
}