///////////////////////////////////////////////////////////////////////////////////////////

// Date : 08-10-2025
// problem : Fibonacci Numbers

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
inline ll power(ll a, ll b, ll mod = MOD) { ll ans = 1; a %= mod; while(b > 0) { if(b & 1) { ans = (ans * a) % mod; } a = (a * a) % mod; b >>= 1; } return ans; }

pair<ll, ll> fib (ll n) {
    if(n==0){return {0,1};}
    auto p=fib(n >> 1);
    ll c=p.first*(2*p.second - p.first);
    ll d=p.first*p.first + p.second*p.second;
    c%=MOD;
    d%=MOD;
    if(n&1){return {d,c+d};}
    else{return {c,d};}
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    vll dp(n+1);
    dp[1]=1;
    dp[0]=1;
    for(int j=2;j<=n;j++){
        for(int i=1;i<=6;i++){
            if(j-i>=0){
                dp[j]+=dp[j-i];
            }
        } 
    }
    for(auto x:dp){
        cout<<x<<' ';
    }
}