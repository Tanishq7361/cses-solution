// Date : 07-01-2026

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 +7;
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
template<class T> 
using ordered_set = tree<T, null_type,less_equal<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// .find_by_order(k)  returns iterator to kth element starting from 0;
// .order_of_key(k) returns count of elements strictly smaller than k;
//  less->less_equal for ordered multiset

int main(){
    fast();
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n),b(n-k+1);
    ordered_set<ll>st;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<k-1;i++){
        st.insert(a[i]);
    }
    for(int i=0;i<(n-k+1);i++){
        st.insert(a[i+k-1]);
        b[i]=*(st.find_by_order(k/2));
        st.erase(st.find(a[i]));
    }
    
}