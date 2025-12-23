///////////////////////////////////////////////////////////////////////////////////////////

// Date : 10-07-2025
// problem : Sliding Window Cost

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
// #include<atcoder/all>
 
using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;
 
template<class T> 
using ordered_set = tree<T, null_type,less_equal<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// .find_by_order(k)  returns iterator to kth element starting from 0;
// .order_of_key(k) returns count of elements strictly smaller than k;
//  less->less_equal for ordered multiset

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n);
    ordered_set<ll>st;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<k;i++){
        st.insert(a[i]);
    }
    auto mid=st.find_by_order(k/2);
    
}