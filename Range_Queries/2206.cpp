///////////////////////////////////////////////////////////////////////////////////////////

// Date : 21-10-2025
// problem : Pizzeria Queries

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

struct SegTree {
    int n;
    vector<ll> seg;
    SegTree(int n): n(n) { seg.assign(4*n, LLONG_MAX); }
    void build(int idx, int l, int r, vector<ll> &a, bool plus) {
        if(l==r){
            seg[idx] = a[l] + (plus ? l : -l);
            return;
        }
        int m=(l+r)/2;
        build(2*idx+1,l,m,a,plus);
        build(2*idx+2,m+1,r,a,plus);
        seg[idx]=min(seg[2*idx+1],seg[2*idx+2]);
    }
    void update(int idx,int l,int r,int pos,ll val,bool plus){
        if(l==r){
            seg[idx] = val + (plus ? l : -l);
            return;
        }
        int m=(l+r)/2;
        if(pos<=m) update(2*idx+1,l,m,pos,val,plus);
        else update(2*idx+2,m+1,r,pos,val,plus);
        seg[idx]=min(seg[2*idx+1],seg[2*idx+2]);
    }
    ll query(int idx,int l,int r,int ql,int qr){
        if(qr<l||r<ql) return LLONG_MAX;
        if(ql<=l&&r<=qr) return seg[idx];
        int m=(l+r)/2;
        return min(query(2*idx+1,l,m,ql,qr),query(2*idx+2,m+1,r,ql,qr));
    }
};


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,q;
    cin>>n>>q;
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    SegTree st1(n), st2(n);
    st1.build(0,0,n-1,a,false);
    st2.build(0,0,n-1,a,true);
    while(q--){
        ll type;
        cin>>type;
        if(type==1){
            ll x,y; 
            cin>>x>>y; 
            st1.update(0,0,n-1,x-1,y,false);
            st2.update(0,0,n-1,x-1,y,true);
        }
        else{
            ll x;
            cin>>x;
            ll left=st1.query(0,0,n-1,0,x-1) +(x-1);
            ll right=st2.query(0,0,n-1,x-1,n-1) -(x-1);
            cout<<min(left,right)<<endl;
        }
    }
}