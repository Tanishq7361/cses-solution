///////////////////////////////////////////////////////////////////////////////////////////

// Date : 21-10-2025
// problem : Prefix Sum Queries

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

class segtree{
private:
    struct Node{
        ll sum;
        ll lazyAdd;
        ll lazySetVal;
        ll prefmx;
        Node(): sum(0),
                lazyAdd(0),
                lazySetVal(LLONG_MIN),
                prefmx(0){}

    };
    vector<Node>seg;
public:
    segtree(ll n){
        seg.resize(4*n +1);
    }
    Node merge(const Node &L, const Node &R) {
        Node P;
        P.sum = L.sum + R.sum;
        P.prefmx=max(L.prefmx,L.sum + R.prefmx);
        return P;
    }
    void push(ll inx, ll low, ll high) {
        Node &node = seg[inx];
        if(node.lazySetVal!=LLONG_MIN){
            node.sum=(high - low + 1)*node.lazySetVal;
            node.prefmx=max(0ll,node.lazySetVal);
            if(low!=high){
                seg[2*inx +1].lazySetVal=node.lazySetVal;
                seg[2*inx +1].lazyAdd=0;
                seg[2*inx +2].lazySetVal=node.lazySetVal;
                seg[2*inx +2].lazyAdd=0;
            }
            node.lazySetVal=LLONG_MIN;
        }
    }


    void updateSet(ll inx, ll low, ll high, ll ql, ll qr, long long val) {
        push(inx,low,high);
        if(qr<low || high<ql){
            return;
        }
        if(ql<=low && high<=qr){
            seg[inx].lazySetVal= val;
            seg[inx].prefmx=max(0ll,val);
            seg[inx].lazyAdd = 0;
            push(inx,low,high);
            return;
        }
        ll mid=(low+high) / 2;
        updateSet(2*inx +1, low, mid, ql, qr, val);
        updateSet(2*inx +2, mid+1, high, ql, qr, val);
        seg[inx]=merge(seg[2*inx +1],seg[2*inx +2]);
    }

    Node querySum(ll inx, ll low, ll high, ll ql, ll qr) {
        Node P;
        push(inx, low, high);
        if(qr<low || high<ql){
            return P;
        }
        if(ql<=low && high<=qr){
            return seg[inx];
        }
        ll mid=(low+high)/2;
        P=merge(querySum(2*inx +1, low, mid, ql, qr),querySum(2*inx +2, mid+1, high, ql, qr));
        return P;
    }

    void build(ll inx, ll low, ll high, vll&arr){
        if(low==high){
            seg[inx].sum=arr[low];
            seg[inx].prefmx=max(0ll,arr[low]);
            return;
        }
        ll mid=(low+high)/2;
        build(2*inx +1,low,mid,arr);
        build(2*inx +2,mid+1,high,arr);
        seg[inx]=merge(seg[2*inx +1],seg[2*inx +2]);
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
    segtree st(n);
    st.build(0,0,n-1,a);

    while(q--){
        ll type,x,y;
        cin>>type>>x>>y;
        if(type==1){
            x--;
            st.updateSet(0,0,n-1,x,x,y);
        }
        else{
            cout<<st.querySum(0,0,n-1,x-1,y-1).prefmx<<endl;
        }
    }
    
}