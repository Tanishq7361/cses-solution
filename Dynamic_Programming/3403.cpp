///////////////////////////////////////////////////////////////////////////////////////////

// Date : 24-07-2025
// problem : Longest common subsequences

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
    vll a(n),b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    vector<vector<ll>>dp(n+1,vll(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
    ll low=n,high=m;
    vll ans;
    while(low>0 && high>0){
        if(a[low-1]==b[high-1]){
            ans.push_back(a[low-1]);
            low--;
            high--;
        }
        else if(dp[low][high]>dp[low][high-1]){
            low--;
        }
        else{
            high--;
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans){
        cout<<x<<' ';
    }
}