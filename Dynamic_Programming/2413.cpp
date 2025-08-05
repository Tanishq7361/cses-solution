///////////////////////////////////////////////////////////////////////////////////////////

// Date : 24-07-2025
// problem : Counting Towers

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define vll vector<long long>

const ll mod=1e9 +7;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    vll dp1(n+1),dp2(n+1);
    dp1[0]=1,dp2[0]=1;
    dp1[1]=1,dp2[1]=2;
    for(int i=2;i<=n;i++){
        dp1[i]=(dp1[i-1]*2)%mod;
    }
    for(int i=2;i<=n;i++){
        dp2[i]=(dp2[i-1]*2)%mod;
    } 
    ll ans=0;
    for(int i=0;i<=n;i++){
        ans+=(dp2[i]*((dp1[n-i]*dp1[n-i])%mod)%mod);
        ans%=mod;
    }
    cout<<ans<<endl;
}