///////////////////////////////////////////////////////////////////////////////////////////

// Date : 08-10-2025
// problem : Nim Game 1

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
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ans=0;
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            ans^=x;
        }
        if(ans){
            cout<<"first"<<endl;
        }
        else{
            cout<<"second"<<endl;
        }
    }
}