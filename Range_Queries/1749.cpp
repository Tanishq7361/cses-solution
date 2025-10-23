///////////////////////////////////////////////////////////////////////////////////////////

// Date : 02-09-2025
// problem : List Removals

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

class segtree{
    vector<ll>seg;
public:
    segtree(ll n){
        seg.resize(4*n +1);
    }
    void build(ll inx, ll low, ll high, vll&arr){
        if(low==high){
            seg[inx]=arr[low];
            return;
        }
        ll mid=(low+high)/2;
        build(2*inx +1,low,mid,arr);
        build(2*inx +2,mid+1,high,arr);
        seg[inx]=min(seg[2*inx +1],seg[2*inx +2]);
    }

    ll query(ll inx, ll low, ll high, ll lq, ll rq){
        // no overlap
        if(rq<low || lq>high){
            return LLONG_MAX;
        }
        // complete overlap
        if(low>=lq && high<=rq){
            return seg[inx];
        }
        // partial overlap is left
        ll mid=(low+high)/2;
        ll left=query(2*inx +1,low,mid,lq,rq);
        ll right=query(2*inx +2,mid+1,high,lq,rq);
        return min(left,right);
    }

    void update(ll inx, ll low, ll high, ll i, ll val,vll&arr){
        if(low==high){
            seg[inx]=val;
            return;
        }
        ll mid=(low+high)/2;
        if(i<=mid){
            update(2*inx +1,low,mid,i,val,arr);
        }
        else{
            update(2*inx +2,mid+1,high,i,val,arr);
        }
        seg[inx]=min(seg[2*inx +1],seg[2*inx +2]);
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    vll a(n),b(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
}