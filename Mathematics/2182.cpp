// Date : 17-11-2025

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

const int MOD = 1e9 +7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin>>n;
    vector<ll> fact;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            fact.push_back(i);
            if((n/i)==i){
                continue;
            }
            fact.push_back(n/i);
        }
    }
    ll ans1=1,ans2=accumulate(fact.begin(),fact.end(),0ll);
    for(auto x:fact){
        ans1=ans1*x;
        ans1%=MOD;
    }
    cout<<ans1<<' '<<ans2<<endl;
    
}