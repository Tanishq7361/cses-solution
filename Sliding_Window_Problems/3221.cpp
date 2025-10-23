///////////////////////////////////////////////////////////////////////////////////////////

// Date : 08-09-2025
// problem : Sliding Window Minimum

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
    ll k,n;
    ll a,b,x,c;
    cin>>n>>k;
    cin>>x>>a>>b>>c;
    priority_queue<pll,vector<pll>,greater<pll>>pq;
    ll curr=x;
    for(int i=0;i<k;i++){
        pq.push({curr,i});
        curr=(a*curr +b)%c;
    }
    ll ans=pq.top().first;
    for(int i=k;i<n;i++){
        pq.push({curr,i});
        curr=(a*curr +b)%c;
        while(pq.top().second+k <= i){
            pq.pop();
        }
        ans^=pq.top().first;
    }
    cout<<ans<<endl;
}