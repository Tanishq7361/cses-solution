///////////////////////////////////////////////////////////////////////////////////////////

// Date : 03-09-2025
// problem : Rectangle Cutting

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// .find_by_order(k)  returns iterator to kth element starting from 0;
// .order_of_key(k) returns count of elements strictly smaller than k;

#define ll long long
#define vll vector<long long>
#define pb push_back
#define pll pair<ll,ll>

ll dp[501][501];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll a,b;
    cin>>a>>b;
    for(int i=0;i<501;i++){
        for(int j=0;j<501;j++){
            dp[i][j]=INT_MAX;
        }
    }
    for(int i=0;i<501;i++){
        dp[i][i]=0;
    }
    for(int i=1;i<501;i++){
        dp[i][1]=i-1;
        dp[1][i]=i-1;
    }
    for(int i=2;i<501;i++){
        for(int j=i+1;j<501;j++){
            for(int k=1;k<= j/2;k++){
                dp[i][j]=min(dp[i][k]+dp[i][j-k]+1,dp[i][j]);
            }
            for(int k=1;k<= i/2;k++){
                dp[i][j]=min(dp[k][j]+dp[i-k][j]+1,dp[i][j]);
            }
            dp[j][i]=dp[i][j];
        }
    }
    cout<<dp[a][b]<<endl;
}