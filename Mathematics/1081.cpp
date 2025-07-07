///////////////////////////////////////////////////////////////////////////////////////////

// Date : 06-07-2025
// problem : Common Divisors

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    vll a(n);
    unordered_map<ll,ll>mpp;
    ll mx=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mpp[a[i]]++;
        mx=max(mx,a[i]);
    }
    ll ans=1;
    vector<ll> fact(mx+1,0);
    for(int i=2;i<=mx;i++){
        for(int j=i;j<=mx;j+=i){
            if(mpp[j]>0){fact[i]+=mpp[j];}
            if(fact[i]>1){ans=i;}
        }
    }
    cout<<ans<<endl;
}