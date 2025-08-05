///////////////////////////////////////////////////////////////////////////////////////////

// Date : 22-07-2025
// problem : Coin Combinations I

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

const ll mod=1e9 +7;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,x;
    cin>>n>>x;
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vll dp(x+1);
    dp[0]=1;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(a[j]>i){continue;}
            dp[i]+=dp[i-a[j]];
            dp[i]%=mod;
        }
    }
    cout<<dp[x]<<endl;
}