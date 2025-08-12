///////////////////////////////////////////////////////////////////////////////////////////

// Date : 13-08-2025
// problem : Range Update Queries

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define vll vector<long long>

class ST{
    vector<ll>seg,lazy;
public:
    ST(ll n){
        seg.resize(4*n);
        lazy.resize(4*n);
    }
    void build(ll inx, ll low, ll high, vll&a){
        if(low==high){
            seg[inx]=a[low];
            return;
        }
        ll mid=(low+high)/2;
        build(2*inx +1, low, mid, a);
        build(2*inx +2, mid+1, high, a);
        seg[inx]=seg[2*inx +1] + seg[2*inx +2];
    }
    void update(ll inx, ll low, ll high, ll l, ll r, ll val){
        // if previous lazy is not computed on that index
        if(lazy[inx]!=0){
            seg[inx]+=(high-low+1)*lazy[inx];
            if(low!=high){
                lazy[2*inx +1]+=lazy[inx];
                lazy[2*inx +2]+=lazy[inx];
            }
            lazy[inx]=0;
        }
        // no overlap
        if(high<l || r<low){
            return;
        }
        // complete overlap
        if(low>=l && high<=r){
            seg[inx]+=(high-low+1)*val;
            if(low!=high){
                lazy[2*inx +1]+=val;
                lazy[2*inx +2]+=val;
            }
            return;
        }
        //partial overlap
        ll mid=(low+high)/2;
        update(2*inx +1,low,mid,l,r,val);
        update(2*inx +2,mid+1,high,l,r,val);
        seg[inx]=seg[2*inx +1]+seg[2*inx +2];
    }
    ll query(ll inx, ll low, ll high, ll k){
        if(lazy[inx]!=0){
            seg[inx]+=(high-low+1)*lazy[inx];
            if(low!=high){
                lazy[2*inx +1]+=lazy[inx];
                lazy[2*inx +2]+=lazy[inx];
            }
            lazy[inx]=0;
        }
        if(low==high){
            return seg[inx];
        }
        ll mid=(low+high)/2;
        if(k>mid){
            return query(2*inx +2,mid+1,high,k);
        }
        else{
            return query(2*inx +1,low,mid,k);
        }
    }
};

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,q;
    cin>>n>>q;
    vll a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ST sg1(n);
    sg1.build(0,0,n-1,a);
    for(ll i=0;i<q;i++){
        ll w;
        cin>>w;
        if(w==1){
            ll x,y,z;
            cin>>x>>y>>z;
            sg1.update(0,0,n-1,x-1,y-1,z);
        }
        else{
            ll x1;
            cin>>x1;
            cout<<sg1.query(0,0,n-1,x1-1)<<endl;
        }
    }
}