///////////////////////////////////////////////////////////////////////////////////////////

// Date : 11-08-2025
// problem : Static Range Minimum Queries

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define vll vector<long long>

void build(int inx, int low, int high, vll&seg, vll &arr){
    if(low==high){
        seg[inx]=arr[low];
        // cout<<inx<<' '<<low<<' '<<arr[low]<<endl;
        return;
    }
    int mid=(low+high)/2;
    build(2*inx +1,low,mid,seg,arr);
    build(2*inx +2,mid+1,high,seg,arr);
    seg[inx]=min(seg[2*inx +1],seg[2*inx +2]);
}

int query(int inx, int low, int high, int l, int r, vll &seg){
    // no overlap
    if(r<low || l>high){
        return INT_MAX;
    }
    // complete overlap
    if(low>=l && high<=r){
        return seg[inx];
    }
    // partial overlap is left
    int mid=(low+high)/2;
    int left=query(2*inx +1,low,mid,l,r,seg);
    int right=query(2*inx +2,mid+1,high,l,r,seg);
    return min(left,right);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,q;
    cin>>n>>q;
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vll seg(4*n);
    build(0,0,n-1,seg,a);
    while(q--){
        ll x,y;
        cin>>x>>y;
        cout<<query(0,0,n-1,x-1,y-1,seg)<<endl;
    }
}