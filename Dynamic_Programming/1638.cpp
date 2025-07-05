///////////////////////////////////////////////////////////////////////////////////////////

// Date : 05-07-2025
// problem : Grid Path 1

#include <bits/stdc++.h>
using namespace std;
const long long MOD=1e9 +7;
#define ll long long
#define vll vector<long long>
int main()
{
    ll n;
    cin>>n;
    vector<vector<char>>a(n,vector<char>(n));
    vector<ll>dp(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]=='*'){dp[j]=0;}
            else if(i==0 && j==0){dp[j]=1;}
            else if(j>0){
                dp[j]+=dp[j-1];
                dp[j]%=MOD;
            }
        }
    }
    cout<<dp[n-1]<<endl;
}