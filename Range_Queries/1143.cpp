///////////////////////////////////////////////////////////////////////////////////////////

// Date : 02-09-2025
// problem : Hotel Queries 

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define vll vector<long long>
#define pb push_back
#define pll pair<ll,ll>

vll ans;

class segtree{
    vector<ll>seg,idx;
public:
    segtree(ll n){
        seg.resize(4*n +1);
        idx.resize(4*n +1);
    }
    void build(ll inx, ll low, ll high, vll&arr){
        if(low==high){
            seg[inx]=arr[low];
            idx[inx]=low;
            return;
        }
        ll mid=(low+high)/2;
        build(2*inx +1,low,mid,arr);
        build(2*inx +2,mid+1,high,arr);
        if(seg[2*inx +1]>=seg[2*inx +2]){
            idx[inx]=idx[2*inx +1];
        }
        else{
            idx[inx]=idx[2*inx +2];
        }
        seg[inx]=max(seg[2*inx +1],seg[2*inx +2]);
    }

    void update(ll inx, ll low, ll high, ll val, vll&arr){
        if(seg[inx]<val){
            return ;
        }
        if(low==high){
            seg[inx]-=val;
            ans.pb(idx[inx]+1);
            return ;
        }
        ll mid=(low+high)/2;
        if(seg[2*inx +1]>=val){
            update(2*inx +1,low,mid,val,arr);
        }
        else{
            update(2*inx +2,mid+1,high,val,arr);
        }
        // now update
        if(seg[2*inx +1]>=seg[2*inx +2]){
            idx[inx]=idx[2*inx +1];
        }
        else{
            idx[inx]=idx[2*inx +2];
        }
        seg[inx]=max(seg[2*inx +1],seg[2*inx +2]);
    }
    void query(ll inx,ll low,ll high,ll val,vll&arr){
        if(seg[0]<val){
            ans.pb(0);
            return;
        }
        update(inx,low,high,val,arr);
        return ;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // maza aa gaya first try me sahi without compilation error
    ll n,m;
    cin>>n>>m;
    vll a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    segtree s(n);
    s.build(0,0,n-1,a);

    while(m--){
        ll x;
        cin>>x;
        s.query(0,0,n-1,x,a);
    }
    for(auto x:ans)
        cout<<x<<' ';
}