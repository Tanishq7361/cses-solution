// Date : 04-11-2025

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

const int MOD = 1e9 +7;

ll dp[2][5001][5001];

ll rec(ll man,ll low,ll high,vll&a){
    if(high<low) return 0;
    if(low==high) return dp[man][low][high] = (man == 0 ? a[low] : 0);
    if(dp[man][low][high]!=LLONG_MIN) return dp[man][low][high];
    if(man){
        return dp[man][low][high]=min(rec(man^1,low+1,high,a),rec(man^1,low,high-1,a));
    }
    return dp[man][low][high]=max(rec(man^1,low+1,high,a)+a[low],rec(man^1,low,high-1,a)+a[high]);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<5001;i++){
        for(int j=0;j<5001;j++){
            for(int k=0;k<2;k++){
                dp[k][i][j]=LLONG_MIN;
            }
        }
    }
    cout<<rec(0,0,n-1,a)<<endl;
}