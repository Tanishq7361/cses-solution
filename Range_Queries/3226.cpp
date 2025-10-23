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
private:
    struct Node{
        ll sum;
        ll prefsum;
        ll suffsum;
        ll anssum;
        Node(): sum(0),
                prefsum(0),
                suffsum(0),
                anssum(0){}
    };
    vector<Node>seg;
public:
    segtree(ll n){
        seg.resize(4*n +1);
    }

    Node merge(const Node &L, const Node &R) {
        Node P;
        P.sum = L.sum + R.sum;
        P.prefsum = max(L.sum+R.prefsum,L.prefsum);
        P.suffsum = max(R.sum+L.suffsum,R.suffsum);
        P.anssum = max({L.anssum,R.anssum,L.suffsum+R.prefsum});
        return P;
    }
    void build(ll inx, ll low, ll high, vll&arr){
        if(low==high){
            seg[inx].sum=arr[low];
            seg[inx].prefsum=max(0ll,arr[low]);
            seg[inx].suffsum=max(0ll,arr[low]);
            seg[inx].anssum=max(0ll,arr[low]);
            return;
        }
        ll mid=(low+high)/2;
        build(2*inx +1,low,mid,arr);
        build(2*inx +2,mid+1,high,arr);
        seg[inx]=merge(seg[2*inx +1],seg[2*inx +2]);
    }

    Node query(ll inx, ll low, ll high, ll lq, ll rq){
        // no overlap
        Node P;
        if(rq<low || lq>high || low>high){
            return P;
        }
        // complete overlap
        if(low>=lq && high<=rq){
            return seg[inx];
        }
        // partial overlap is left
        ll mid=(low+high)/2;
        Node left=query(2*inx +1,low,mid,lq,rq);
        Node right=query(2*inx +2,mid+1,high,lq,rq);
        P=merge(left,right);
        return P;
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
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
        cout<<st.query(0,0,n-1,x,y).anssum<<endl;
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