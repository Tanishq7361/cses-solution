///////////////////////////////////////////////////////////////////////////////////////////

// Date : 02-11-2025
// problem : Movie Festival II

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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vector<pair<ll,ll>>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].second>>a[i].first;
    }
    sort(a.begin(),a.end());
    ll prev=-1;
    ll ct=0;
    for(int i=0;i<n;i++){
        if(a[i].second>prev){
            prev=a[i].first;
            ct++;
        }
    }
    cout<<ct<<endl;
    
}