// created: 13.10.2025

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll   long long
#define stc  static_cast
#define vll  vector<ll>
#define vpll vector<pair<ll,ll>>
#define pll  pair<ll, ll>
#define pb   push_back
#define ff   first
#define ss   second
#define done return
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define vin(T, a, n)              \
    vector<T> a(n);                  \
    for (ll i = 0; i < n; i++) \
        cin >> a[i];
inline ll gcd(ll a, ll b) { if(b == 0) return a; return gcd(b, a % b); }
inline ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }

class segtree{
    vector<tuple<ll,ll,ll,ll>>seg;
public:
    segtree(ll n){
        seg.resize(4*n +1);
    }

    tuple<ll,ll,ll,ll>combine(tuple<ll,ll,ll,ll>&a,tuple<ll,ll,ll,ll>&b){
        tuple<ll,ll,ll,ll>ans;
        auto [lefs,lefps,lefss,lefans]=a;
        auto [rigs,rigps,rigss,rigans]=b;
        ans={lefs+rigs,max(lefps,lefs+rigps),max(rigss,lefss+rigs),max({lefans,rigans,lefss+rigps})};
        return ans;
    }

    void build(ll inx, ll low, ll high, vll&arr){
        if(low==high){
            seg[inx]={arr[low],max(0ll,arr[low]),max(0ll,arr[low]),max(0ll,arr[low])};
            return;
        }
        ll mid=(low+high)/2;
        build(2*inx +1,low,mid,arr);
        build(2*inx +2,mid+1,high,arr);
        seg[inx]=combine(seg[2*inx +1],seg[2*inx +2]);
    }

    void update(ll inx, ll low, ll high, ll i, ll val){
        if(low==high){
            seg[inx]={val,max(0ll,val),max(0ll,val),max(0ll,val)};
            return;
        }
        ll mid=(low+high)/2;
        if(i<=mid){
            update(2*inx +1,low,mid,i,val);
        }
        else{
            update(2*inx +2,mid+1,high,i,val);
        }
        seg[inx]=combine(seg[2*inx +1],seg[2*inx +2]);
    }

    void query(){
        cout<<get<3>(seg[0])<<endl;
    }
};

void solve()
{
    ll n,q;
    cin>>n>>q;
    vin(ll,a,n);
    
    segtree st(n);
    st.build(0,0,n-1,a);

    while(q--){
        ll idx,val;
        cin>>idx>>val;
        idx--;
        st.update(0,0,n-1,idx,val);
        st.query();
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll tt = 1;
    while (tt--)
    { solve(); }
    return 0;
}