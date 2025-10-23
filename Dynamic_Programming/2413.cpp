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
    vector<vll> dp(1000001,vll(2));
    // there are 2 step either close this till now or remain open
    // dp[i][0] till ith index last row has 2 growing block
    // dp[i][0] till ith index last row has 1 growing block
    dp[1000000][0]=1;
    dp[1000000][1]=1;
    for(int i=999999;i>=0;i--){

        // case-1.a close them and add (1*2 block or 2* (1*1) blocks) 
        // case-2.a close 1 of them and open for 2nd and vice versa
        // case-3.a remains open both

        dp[i][0] += (dp[i+1][0] + dp[i+1][1]) + (2*dp[i+1][0]) + (dp[i+1][0]);
        dp[i][0] %=mod;

        // case-1.b close it and add (1*2 block or 2* (1*1) blocks) 
        // case-2.b remains open both

        dp[i][1] += (dp[i+1][1] + dp[i+1][0]) + (dp[i+1][1]);
        dp[i][1] %=mod;
    }
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<(dp[1000000-n+1][0]+dp[1000000-n+1][1])%mod<<endl;
    }
}