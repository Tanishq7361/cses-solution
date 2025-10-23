///////////////////////////////////////////////////////////////////////////////////////////

// Date : 14-08-2025
// problem : Array Description

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define vll vector<long long>

const long long int MOD=1e9 +7;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<ll>> dp(n,vll (m+2));
    if(a[0]!=0){
        dp[0][a[0]]=1;
    }
    else{
        for(int i=1;i<=m;i++){
            dp[0][i]=1;
        }
    }
    for(int i=1;i<n;i++){
        if(a[i]==0){
            for(int j=1;j<=m;j++){
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1]+dp[i-1][j+1];
                dp[i][j]%=MOD;
            }
        }
        else{
            dp[i][a[i]]=dp[i-1][a[i]]+dp[i-1][a[i]-1]+dp[i-1][a[i]+1];
            dp[i][a[i]]%=MOD;
        }
        
    }
    ll ans=0;
    for(int i=1;i<=m;i++){
        ans+=dp[n-1][i];
        ans%=MOD;
    }
    cout<<ans<<endl;
}