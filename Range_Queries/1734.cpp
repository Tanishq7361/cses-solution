///////////////////////////////////////////////////////////////////////////////////////////

// Date : 25-10-2025
// problem : Distinct Values Queries

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// .find_by_order(k)  returns iterator to kth element starting from 0;
// .order_of_key(k) returns count of elements strictly smaller than k;

struct custom_hash { //to avoid TLE due to collision in unordered_map
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    template<typename L, typename R>
    size_t operator()(pair<L,R> const& Y) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31 + Y.second + FIXED_RANDOM);
    }
};

#define ll long long
#define vll vector<long long>
#define pb push_back
#define pll pair<ll,ll>

const int MOD = 1e9 +7;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,q;
    cin>>n>>q;
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll z=sqrt(n);
    vector<unordered_map<ll,ll,custom_hash>> decom(z+1);
    ll ct=0;
    for(int i=0;i<n;i++){
        unordered_map<ll,ll,custom_hash>mpp;
        for(int j=0;i<n && j<z;j++){
            mpp[a[i]]++;
            i++;
        }
        decom[ct]=mpp;
        ct++;
    }
    while(q--){
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
        

    }
    
}