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
    vector<ll>seg,lazy,gcdd;
    vpll mn,mx;
public:
    segtree(ll n){
        seg.resize(4*n +1);
        lazy.resize(4*n +1);
        mn.resize(4*n +1);
        mx.resize(4*n +1);
        gcdd.resize(4*n +1);
    }
    void build(ll inx, ll low, ll high, vll&arr){
        if(low==high){
            seg[inx]=arr[low];
            mn[inx]={arr[low],1};
            mx[inx]={arr[low],1};
            gcdd[inx]=arr[low];
            return;
        }
        ll mid=(low+high)/2;
        build(2*inx +1,low,mid,arr);
        build(2*inx +2,mid+1,high,arr);
        seg[inx]=seg[2*inx +1]+seg[2*inx +2];
        if(mn[2*inx +1].ff==mn[2*inx +2].ff){
            mn[inx]={mn[2*inx +1].ff,mn[2*inx +1].ss+mn[2*inx +2].ss};
        }
        else if(mn[2*inx +1].ff>mn[2*inx +2].ff){
            mn[inx]=mn[2*inx +2];
        }
        else{
            mn[inx]=mn[2*inx +1];
        }
        if(mx[2*inx +1].ff==mx[2*inx +2].ff){
            mx[inx]={mx[2*inx +1].ff,mx[2*inx +1].ss+mx[2*inx +2].ss};
        }
        else if(mx[2*inx +1].ff<mx[2*inx +2].ff){
            mx[inx]=mx[2*inx +2];
        }
        else{
            mx[inx]=mx[2*inx +1];
        }
        gcdd[inx]=gcd(gcdd[2*inx +1],gcdd[2*inx +2]);
    }

    void update(ll inx, ll low, ll high, ll i, ll val){
        if(low==high){
            seg[inx]=val;
            mn[inx]={val,1};
            mx[inx]={val,1};
            gcdd[inx]=val;
            return;
        }
        ll mid=(low+high)/2;
        if(i<=mid){
            update(2*inx +1,low,mid,i,val);
        }
        else{
            update(2*inx +2,mid+1,high,i,val);
        }
        seg[inx]=seg[2*inx +1]+seg[2*inx +2];
        if(mn[2*inx +1]==mn[2*inx +2]){
            mn[inx]={mn[2*inx +1].ff,mn[2*inx +1].ss+mn[2*inx +2].ss};
        }
        else if(mn[2*inx +1]>mn[2*inx +2]){
            mn[inx]=mn[2*inx +2];
        }
        else{
            mn[inx]=mn[2*inx +1];
        }
        if(mx[2*inx +1]==mx[2*inx +2]){
            mx[inx]={mx[2*inx +1].ff,mx[2*inx +1].ss+mx[2*inx +2].ss};
        }
        else if(mx[2*inx +1]<mx[2*inx +2]){
            mx[inx]=mx[2*inx +2];
        }
        else{
            mx[inx]=mx[2*inx +1];
        }
        gcdd[inx]=gcd(gcdd[2*inx +1],gcdd[2*inx +2]);
    }

    pll querymn(ll inx, ll low, ll high, ll lq, ll rq){
        // no overlap
        if(rq<low || lq>high || low>high){
            return {INT_MAX,0};
        }
        // complete overlap
        if(low>=lq && high<=rq){
            return mn[inx];
        }
        // partial overlap is left
        ll mid=(low+high)/2;
        pll left=querymn(2*inx +1,low,mid,lq,rq);
        pll right=querymn(2*inx +2,mid+1,high,lq,rq);
        pll ans;
        if(left.ff==right.ff){
           ans={left.ff,right.ss+left.ss};
        }
        else if(left.ff>right.ff){
            ans=right;
        }
        else{
            ans=left;
        }
        return ans;
    }

    pll querymx(ll inx, ll low, ll high, ll lq, ll rq){
        // no overlap
        if(rq<low || lq>high || low>high){
            return {0,0};
        }
        // complete overlap
        if(low>=lq && high<=rq){
            return mx[inx];
        }
        // partial overlap is left
        ll mid=(low+high)/2;
        pll left=querymx(2*inx +1,low,mid,lq,rq);
        pll right=querymx(2*inx +2,mid+1,high,lq,rq);
        pll ans;
        if(left.ff==right.ff){
           ans={left.ff,right.ss+left.ss};
        }
        else if(left.ff<right.ff){
            ans=right;
        }
        else{
            ans=left;
        }
        return ans;
    }

    ll querygcd(ll inx, ll low, ll high, ll lq, ll rq){
        // no overlap
        if(rq<low || lq>high || low>high){
            return 0;
        }
        // complete overlap
        if(low>=lq && high<=rq){
            return gcdd[inx];
        }
        // partial overlap is left
        ll mid=(low+high)/2;
        ll left=querygcd(2*inx +1,low,mid,lq,rq);
        ll right=querygcd(2*inx +2,mid+1,high,lq,rq);
        return gcd(left,right);
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
        if(type==1){
            st.update(0,0,n-1,x,y);
            continue;
        }
        ll ans1=st.query(0,0,n-1,x,y);
        pll ans2=st.querymn(0,0,n-1,x,y);
        pll ans3=st.querymx(0,0,n-1,x,y);
        ll ans4=st.querygcd(0,0,n-1,x,y);
        cout<< ans1<< ' '<<ans2.ff<<' '<<ans2.ss<<' '<<ans3.ff<<' '<<ans3.ss<<' '<<ans4<<endl;
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