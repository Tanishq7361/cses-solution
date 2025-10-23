///////////////////////////////////////////////////////////////////////////////////////////

// Date : 26-08-2025
// problem : 

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    vll a(n);
    // i think this is same as divide array into two sub set such that difference between them is minimum 
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll sum=accumulate(a.begin(),a.end(),0ll);
    ll mx=0;
    vll dp(n+1);

}