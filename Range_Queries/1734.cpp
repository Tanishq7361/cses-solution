///////////////////////////////////////////////////////////////////////////////////////////

// Date : 13-10-2025
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

class segtree{
    vector<ll>seg,lazy;
public:
    segtree(ll n){
        seg.resize(4*n +1);
        lazy.resize(4*n +1);
    }
    void build(ll inx, ll low, ll high, vll&arr,unordered_map<ll,ll,custom_hash>&mpp){
        if(low==high){
            seg[inx]=1;
            mpp[arr[low]]++;
            return;
        }
        ll mid=(low+high)/2;
        build(2*inx +1,low,mid,arr,mpp);
        build(2*inx +2,mid+1,high,arr,mpp);
        seg[inx]=mpp.size();
    }

    void lazyupdate(ll inx, ll low, ll high, ll lq, ll rq, ll val){
        if(lazy[inx]!=0){
            seg[inx]+=(high-low+1)*lazy[inx];
            if(low!=high){
                lazy[2*inx +1]+=lazy[inx];
                lazy[2*inx +2]+=lazy[inx];
            }
            lazy[inx]=0;
        }
        if(rq<low || lq>high || low>high){
            return ;
        }
        if(low>=lq && high<=rq){
            seg[inx]+=(high-low+1)*lazy[inx];
            if(low!=high){
                lazy[2*inx +1]+=lazy[inx];
                lazy[2*inx +2]+=lazy[inx];
            }
            return;
        }
        ll mid=(low+high)/2;
        lazyupdate(2*inx +1,low,mid,lq,rq,val);
        lazyupdate(2*inx +2,mid+1,high,lq,rq,val);
        seg[inx]=seg[2*inx +1]+seg[2*inx +2];
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
    }

    ll query(ll inx, ll low, ll high, ll lq, ll rq){
        // no overlap
        if(rq<low || lq>high || low>high){
            return 0;
        }
        // complete overlap
        if(low>=lq && high<=rq){
            return seg[inx];
        }
        // partial overlap is left
        ll mid=(low+high)/2;
        ll left=query(2*inx +1,low,mid,lq,rq);
        ll right=query(2*inx +2,mid+1,high,lq,rq);
        return left+right;
    }
    
    ll lazyquery(ll inx, ll low, ll high, ll lq, ll rq){
        if(lazy[inx]!=0){
            seg[inx]+=(high-low+1)*lazy[inx];
            if(low!=high){
                lazy[2*inx +1]+=lazy[inx];
                lazy[2*inx +2]+=lazy[inx];
            }
            lazy[inx]=0;
        }
        if(rq<low || lq>high || low>high) return 0;
        if(low>=lq && high<=rq){
            return seg[inx];
        }
        ll mid=(low+high)/2;
        return lazyquery(2*inx +1,low,mid,lq,rq)+lazyquery(2*inx +2,mid+1,high,lq,rq);
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
    unordered_map<ll,ll,custom_hash>mpp;
    segtree st(n);
    st.build(0,0,n-1,a,mpp);

    while(q--){
        ll x,y;
        cin>>x>>y;
        x--;y--;
        cout<<st.query(0,0,n-1,x,y)<<endl;
    }
    
}