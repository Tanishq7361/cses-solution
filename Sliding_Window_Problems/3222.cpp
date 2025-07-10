///////////////////////////////////////////////////////////////////////////////////////////

// Date : 10-07-2025
// problem : Sliding Window Distinct Values

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vll a(n);
    map<ll,ll>mpp;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<k;i++){
        mpp[a[i]]++;
    }
    cout<<mpp.size()<<' ';
    for(int i=k;i<n;i++){
        mpp[a[i]]++;
        mpp[a[i-k]]--;
        if(mpp[a[i-k]]==0){
            mpp.erase(a[i-k]);
        }
        cout<<mpp.size()<<' ';
    }
}