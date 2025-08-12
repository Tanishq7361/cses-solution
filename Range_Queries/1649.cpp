///////////////////////////////////////////////////////////////////////////////////////////

// Date : 11-08-2025
// problem : Dynamic Range Minimum Queries

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define int ll
#define vll vector<long long>
class sgtree{
    vector<int>seg;
public:
    sgtree(int n){
        seg.resize(4*n +1);
    }
    void build(int inx, int low, int high, vll&arr){
        if(low==high){
            seg[inx]=arr[low];
            return;
        }
        int mid=(low+high)/2;
        build(2*inx +1,low,mid,arr);
        build(2*inx +2,mid+1,high,arr);
        seg[inx]=min(seg[2*inx +1],seg[2*inx +2]);
    }

    int query(int inx, int low, int high, int l, int r){
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
        int left=query(2*inx +1,low,mid,l,r);
        int right=query(2*inx +2,mid+1,high,l,r);
        return min(left,right);
    }

    void update(int inx, int low, int high, int i, int val,vll&arr){
        if(low==high){
            seg[inx]=val;
            return;
        }
        int mid=(low+high)/2;
        if(i<=mid){
            update(2*inx +1,low,mid,i,val,arr);
        }
        else{
            update(2*inx +2,mid+1,high,i,val,arr);
        }
        seg[inx]=min(seg[2*inx +1],seg[2*inx +2]);
    }
};
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,q;
    cin>>n>>q;
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sgtree s1(n);
    s1.build(0,0,n-1,a);
    while(q--){
        ll w,x,y;
        cin>>w>>x>>y;
        if(w==1){
            s1.update(0,0,n-1,x-1,y,a);
        }
        else{
            cout<<s1.query(0,0,n-1,x-1,y-1)<<endl;
        }
    }
}