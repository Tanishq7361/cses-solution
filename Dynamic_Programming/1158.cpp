///////////////////////////////////////////////////////////////////////////////////////////

// Date : 24-07-2025
// problem : Book Shop

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vll a(n);
    vll b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vector<vector<ll>>dp(n+1,vector<ll>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i-1][j];
            if(a[i]<=j){
                dp[i][j]=max(dp[i][j-a[i]]+b[i],dp[i-1][j]);
            }
        }
    }
    cout<<dp[n][n]<<endl;
}