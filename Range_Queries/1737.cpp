// created: 19.10.2025

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
        ll lazyAdd;
        ll lazySetVal;
        Node(): sum(0),
                lazyAdd(0),
                lazySetVal(LLONG_MIN){}
    };
    vector<Node>seg;
public:
    segtree(ll n){
        seg.resize(4*n +1);
    }
    Node merge(const Node &L, const Node &R) {
        Node P;
        P.sum = L.sum + R.sum;
        return P;
    }
    void push(ll inx, ll low, ll high) {
        Node &node = seg[inx];
        if(node.lazySetVal!=LLONG_MIN){
            node.sum=(high - low + 1)*node.lazySetVal;
            if(low!=high){
                seg[2*inx +1].lazySetVal=node.lazySetVal;
                seg[2*inx +1].lazyAdd=0;
                seg[2*inx +2].lazySetVal=node.lazySetVal;
                seg[2*inx +2].lazyAdd=0;
            }
            node.lazySetVal=LLONG_MIN;
        }
        if(node.lazyAdd!=0){ 
            node.sum+=(high - low + 1)*node.lazyAdd;
            if(low!=high) {
                if(seg[2*inx +1].lazySetVal!=LLONG_MIN){
                    seg[2*inx +1].lazySetVal += node.lazyAdd;
                }
                else{
                    seg[2*inx +1].lazyAdd += node.lazyAdd;
                }
                if(seg[2*inx +2].lazySetVal!=LLONG_MIN){
                    seg[2*inx +2].lazySetVal += node.lazyAdd;
                }
                else{
                    seg[2*inx +2].lazyAdd += node.lazyAdd;
                }
            }
            node.lazyAdd=0;
        }
    }

    void updateAdd(ll inx, ll l, ll r, ll ql, ll qr, long long val) {
        push(inx, l, r);
        if(qr < l || r < ql){
            return;
        }
        if(ql<=l && r<=qr){
            seg[inx].lazyAdd+=val;
            push(inx,l,r);
            return;
        }
        ll mid=(l+r)/2;
        updateAdd(2*inx +1, l, mid, ql, qr, val);
        updateAdd(2*inx +2, mid+1, r, ql, qr, val);
        seg[inx]=merge(seg[2*inx +1],seg[2*inx +2]);
    }

    void updateSet(ll inx, ll low, ll high, ll ql, ll qr, long long val) {
        push(inx,low,high);
        if(qr<low || high<ql){
            return;
        }
        if(ql<=low && high<=qr){
            seg[inx].lazySetVal= val;
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
            return;
        }
        ll mid=(low+high)/2;
        build(2*inx +1,low,mid,arr);
        build(2*inx +2,mid+1,high,arr);
        seg[inx]=merge(seg[2*inx +1],seg[2*inx +2]);
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
        ll type;
        cin>>type;
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
        if(type==1){
            ll val;
            cin>>val;
            st.updateAdd(0,0,n-1,x,y,val);
        }
        else if(type==2){
            ll val;
            cin>>val;
            st.updateSet(0,0,n-1,x,y,val);
        }
        else{
            cout<<st.querySum(0,0,n-1,x,y).sum<<endl;
        }
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