#include <bits/stdc++.h>
using namespace std;

#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// .find_by_order(k)  returns iterator to kth element starting from 0;
// .order_of_key(k) returns count of elements strictly smaller than k;
//  less->less_equal for ordered multiset

const long long MAXX=1e18 +13;
const long long MOD=1e9 +7;
const long long MOD1=998244353;
const long long NMOD=999999883;

#define endl            '\n'
#define ll              long long
#define vll             vector<ll>
#define vvll            vector<vector<ll>>
#define vpll            vector<pair<ll,ll>>
#define pll             pair<ll,ll>
#define pb              push_back
#define bitcnt          __builtin_popcountll
#define ff              first
#define ss              second
#define yes             cout<<"Yes\n"
#define no              cout<<"No\n"
#define mone            cout<<-1<<endl
#define done            return
#define rep(i,l,r)      for(ll i=(l);i<(r);i++)
#define repr(i,r,l)     for(ll i=(r-1);i>=l;i--)
#define all(x)          (x).begin(),(x).end()
#define srt(x)          sort((x).begin(),(x).end())
#define rev(x)          reverse(x.begin(),x.end())
#define maxvl(v)        *max_element((v).begin(),(v).end())
#define minvl(v)        *min_element((v).begin(),(v).end())
#define fastio          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define flush           cout.flush()
#define deb(x)          cerr<<(#x)<<" is "<<(x)<<endl
#define pi              3.14159265358979
#define vin(T,a,n)      vector<T>a(n); rep(i,0,n) cin>>a[i];
#define vvin(T,a,n,m)   vector<vector<T>>a(n,vector<T>(m)); rep(i,0,n) rep(j,0,m) cin>>a[i][j];
inline  bool            compar(pair<ll,ll>a,pair<ll,ll>b){if(a.ff==b.ff){return a.ss<b.ss;} else{return a.ff>b.ff;}}
inline  bool            fastprime(ll n){return n>1 && (n<=3 || (n%2 && n%3 && [&](){for(ll i=5;i*i<=n;i+=6) if(n%i==0||n%(i+2)==0) return false; return true;}()));}
inline  ll              powerfn(ll a,ll b,ll mod=MOD){ll ans=1; a%=mod; while(b>0){ if(b&1){ans=(ans*a)%mod;} a=(a*a)%mod; b>>=1;} return ans;}
inline  ll              modsum(ll a,ll b,ll mod=MOD){return ((a%mod + b%mod)%mod);}
inline  ll              modmul(ll a,ll b,ll mod=MOD){return ((a%mod * b%mod)%mod);}
inline  ll              modinv(ll a,ll mod=MOD){return powerfn(a,mod-2,mod);}
inline  ll              msbpos(ll n){if(n==0) return -1; return (63-(__builtin_clzll(n)));}
inline  ll              gcd(ll a,ll b){if(b==0) return a; return gcd(b,a%b);}
inline  ll              lcm(ll a,ll b){return (a/gcd(a,b) *b);}
inline  ll              nCr(ll n,ll r){if(r>n) return 0; if(r>n-r) r=n-r; ll res=1; for(ll i=1;i<=r;i++) res=res*(n-i+1)/i; return res;}
inline  ll              ansxor(ll n){return n%4==0 ? n : n%4==1 ? 1 : n%4==2 ? n+1 : 0;}
const   vector<ll>dx    ={1,0,-1,0,1,1,-1,-1};
const   vector<ll>dy    ={0,1,0,-1,1,-1,1,-1};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>void vout(vector<T>&n){for(auto &x:n){cout<<x<<' ';}cout<<endl;}
template<class T>void vout(vector<vector<T>>&n){for(auto &x:n){for(auto &y:x){cout<<y<<' ';}cout<<endl;}}
#define vpout(a) for(auto x:a){cout<<x.first<<' '<<x.second<<endl;}
#define o1(a) cout<<a<<endl

//--------------------------------Segment Tree-------------------------------//

class segtree{
private:
    struct Node{
        ll sum;
        ll lazyAdd;
        ll lazySet;
        Node(): sum(0),
                lazyAdd(0),
                lazySet(LLONG_MIN){}
    };
    vector<Node>seg;
    ll n;
public:
    segtree(ll n, vll &arr){
        this->n=n;
        seg.resize(4*n +5);
        build(0,0,n-1,arr);
    }

    Node merge(const Node &L, const Node &R){
        Node P;
        P.sum = L.sum + R.sum;
        return P;
    }

    void push(ll inx, ll low, ll high){
        Node &node = seg[inx];
        if(node.lazySet!=LLONG_MIN){
            node.sum=(high - low + 1)*node.lazySet;
            if(low!=high){
                seg[2*inx +1].lazySet=node.lazySet;
                seg[2*inx +1].lazyAdd=0;
                seg[2*inx +2].lazySet=node.lazySet;
                seg[2*inx +2].lazyAdd=0;
            }
            node.lazySet=LLONG_MIN;
        }
        if(node.lazyAdd!=0){ 
            node.sum+=(high - low + 1)*node.lazyAdd;
            if(low!=high){
                if(seg[2*inx +1].lazySet!=LLONG_MIN){seg[2*inx +1].lazySet += node.lazyAdd;}
                else{seg[2*inx +1].lazyAdd += node.lazyAdd;}
                if(seg[2*inx +2].lazySet!=LLONG_MIN){seg[2*inx +2].lazySet += node.lazyAdd;}
                else{seg[2*inx +2].lazyAdd += node.lazyAdd;}
            }
            node.lazyAdd=0;
        }
    }

    void updateAdd(ll inx, ll low, ll high, ll ql, ll qr, long long val){
        push(inx,low,high);
        if(qr<low || high<ql){return;}
        if(ql<=low && high<=qr){
            seg[inx].lazyAdd+=val;
            push(inx,low,high);
            return;
        }
        ll mid=(low+high)/2;
        updateAdd(2*inx +1,low,mid,ql,qr,val);
        updateAdd(2*inx +2,mid+1,high,ql,qr,val);
        seg[inx]=merge(seg[2*inx +1],seg[2*inx +2]);
    }

    void updateSet(ll inx, ll low, ll high, ll ql, ll qr, long long val){
        push(inx,low,high);
        if(qr<low || high<ql){return;}
        if(ql<=low && high<=qr){
            seg[inx].lazySet= val;
            seg[inx].lazyAdd = 0;
            push(inx,low,high);
            return;
        }
        ll mid=(low+high) / 2;
        updateSet(2*inx +1, low, mid, ql, qr, val);
        updateSet(2*inx +2, mid+1, high, ql, qr, val);
        seg[inx]=merge(seg[2*inx +1],seg[2*inx +2]);
    }

    Node querySum(ll inx, ll low, ll high, ll ql, ll qr){
        Node P;
        push(inx, low, high);
        if(qr<low || high<ql){return P;}
        if(ql<=low && high<=qr){return seg[inx];}
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
    void updateSetPoint(ll inx, ll val){ updateSet(0,0,n-1,inx,inx,val);}
    void updateSetRange(ll ql, ll qr, ll val){ updateSet(0,0,n-1,ql,qr,val);}
    void updateAddPoint(ll inx, ll val){ updateAdd(0,0,n-1,inx,inx,val);}
    void updateAddRange(ll ql, ll qr, ll val){ updateAdd(0,0,n-1,ql,qr,val);}

};
//---------------------------------------------------------------------------------------//

//----------------------------------String Algo-------------------------------------//

vector<ll>z_f(string s){//Z[i] = length of longest substring starting at i that matches prefix
    int n=s.size();
    vector<ll>z(n);
    ll l=0,r=0;
    for(ll i=1;i<n;i++){
        if(i<r){
            z[i]=min(r-i,z[i-l]);
        }
        while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
            z[i]++;
        }
        if(i+z[i]>r){
            l=i;
            r=i+z[i];
        }
    }
    return z;
}

vector<ll>prefix_f(string s){
    //pi2[i] is the length of the longest proper prefix of the substring s[0..i] which is also a suffix of this substring.
    ll n=s.size();
    vector<ll>pi2(n);
    for(ll i=1;i<n;i++){
        ll j=pi2[i-1];
        while(j>0 && s[i]!=s[j]) j=pi2[j-1];
        if(s[i]==s[j]) j++;
        pi2[i]=j;
    }
    return pi2;
}

string min_cycle(string s){
    s+=s;
    ll n=s.size();
    ll low=0,ans=0;
    while(low<n/2){
        ans=low;
        ll high=low+1,k=low;
        while(high<n && s[k]<=s[high]){
            if(s[k]<s[high]) k=low;
            else k++;
            high++;
        }
        while(low<=k) low+=high-k;
    }
    return s.substr(ans,n/2);
}

string maxpalin(string s){//Manacher’s Algorithm
    string t="#";
    for(char c:s){
        t+=c;
        t+="#";
    }
    ll n=t.size();
    vector<ll>p(n);
    ll low=0,high=0;
    ll mx=0,inx=0;
    for(ll i=0;i<n;i++){
        if (i<high) p[i]=min(high-i,p[low+high-i]);
        // kholvanu
        while(i-p[i]-1>=0 && i+p[i]+1<n && t[i-p[i]-1]==t[i+p[i]+1]){ p[i]++;}
        // update
        if(i+p[i]>high){
            low=i-p[i];
            high=i+p[i];
        }
        // track answer
        if(p[i]>mx){
            mx=p[i],inx=i;
        }
    }
    ll dia=(inx-mx)/2;
    return s.substr(dia,mx);
}

struct Hashing{
    string s; int n;
    ll p1=331,m1=999999937;
    ll p2=379,m2=1e9 + 87;
    vll p_pow1,p_pow2,h1,h2,inv_pow1,inv_pow2;
    Hashing(const string& str) : s(str){
        n=s.length(); p_pow1.resize(n); p_pow2.resize(n);
        h1.resize(n+1);
        h2.resize(n+1);
        inv_pow1.resize(n);
        inv_pow2.resize(n);
        p_pow1[0]=1; p_pow2[0]=1; inv_pow1[0]=1; inv_pow2[0]=1;
        ll inv_p1=modinv(p1,m1); ll inv_p2=modinv(p2,m2);
        for(int i=1;i<n;i++){
            p_pow1[i]=(p_pow1[i-1]*p1) % m1; p_pow2[i]=(p_pow2[i-1]*p2)%m2;
            inv_pow1[i]=(inv_pow1[i-1]*inv_p1) % m1; inv_pow2[i]=(inv_pow2[i-1]*inv_p2)%m2;
        }
        for(int i=0;i<n;i++){
            h1[i+1]=(h1[i]+(s[i] - 'a' +1)*p_pow1[i])%m1;
            h2[i+1]=(h2[i]+(s[i] - 'a' +1)*p_pow2[i])%m2;
        }
    }
    pll get_hash(int l,int r){
        ll res1=(h1[r+1]-h1[l]+m1)%m1; ll res2=(h2[r+1]-h2[l]+m2)%m2;
        res1=(res1*inv_pow1[l])%m1; res2=(res2*inv_pow2[l])%m2;
        return make_pair(res1,res2);
    }
};
    // set hash ((a+k)^h +(b+k)^h + (c+k)^h )%m 
    // k is large upto 10^9 and  60<h<small

//----------------------------------------------------------------------------------//

//------------------------------DSU------------------------------//

class DSU{
private:
    vector<ll>par,size,edge,rank,dist,val;
    ll count;
public:
    DSU(ll n){
        par.resize(n+1);size.assign(n+1,1);
        rank.resize(n+1);edge.resize(n+1);
        dist.resize(n+1);count=n;
        val.resize(n+1);
        iota(par.begin(),par.end(),0);
    }
    ll find(ll x){
        if(x!=par[x]){
            ll p=par[x];
            par[x]=find(par[x]);
            dist[x]+=dist[p];
            val[x]^=val[p];
        }
        return par[x];
    }
    bool unitebysize(ll x,ll y){
        ll ox=x,oy=y;
        x=find(x),y=find(y);
        if(x==y){edge[x]++; return false;}//condn for parity
        if(size[x]<size[y]){swap(x,y); swap(ox,oy);}
        par[y]=x; size[x]+=size[y];
        dist[y]=1;
        val[y]=val[ox]^val[oy];//^edge-weight
        edge[x]+=edge[y]+1;
        count--;
        return true;
    }
    bool unitebyrank(ll x,ll y){
        x=find(x),y=find(y);
        if(x==y){edge[x]++; return false;}
        if(rank[x]<rank[y]){swap(x,y);}
        par[y]=x; dist[y]=1;
        size[x]+=size[y];
        if(rank[x]==rank[y]){rank[x]++;}
        edge[x]+=edge[y]+1;
        count--;
        return true;
    }
    ll compoCount(){return count;}
    ll getSize(ll x){return size[find(x)];}
    ll getEdgeCount(ll x){return edge[find(x)];}
};
//-------------------------------------------------------------------------//

//-------------------------------------Matrix Exponentiation----------------------------//

struct Matrix{
    ll a[2][2]={{0,0},{0,0}};
    Matrix operator*(const Matrix& other) const {
        Matrix product;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    product.a[i][j]+=a[i][k]*other.a[k][j];
                    product.a[i][j]%=MOD;
                }
            }
        }
        return product;
    }
    Matrix operator%(ll mod) const {
        Matrix res;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                res.a[i][j]=a[i][j]%mod;
            }
        }
        return res;
    }
};

Matrix matpow(Matrix Final, ll k){
    Matrix product;
    for(int i=0;i<2;i++){
        product.a[i][i]=1.0;
    }
    while(k>0){
        if(k&1){
            product=product*Final;
        }
        Final=Final*Final;
        k/=2;
    }
    return product;
};

//---------------------------------------------------------------------------------------//

//-------------------------------------HLD--------------------------------//

struct HLD {
    int n;
    std::vector<int> siz, top, dep, par, in, out, ord;
    std::vector<std::vector<int>> adj;
    int cur;
    HLD(){}
    HLD(int n){
        init(n);
    }
    void init(int n){
        this->n=n;
        siz.resize(n);
        top.resize(n);
        dep.resize(n);
        par.resize(n);
        in.resize(n);
        out.resize(n);
        ord.resize(n);
        cur = 0;
        adj.assign(n,{});
    }
    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void work(int root=0){
        top[root]=root;
        dep[root]=0;
        par[root]=-1;
        dfs1(root);
        dfs2(root);
    }
    void dfs1(int u){
        if(par[u]!=-1){
            adj[u].erase(std::find(adj[u].begin(),adj[u].end(),par[u]));
        }
        siz[u]=1;
        for(auto &v:adj[u]){
            par[v]=u;
            dep[v]=dep[u]+1;
            dfs1(v);
            siz[u]+=siz[v];
            if(siz[v]>siz[adj[u][0]]){
                std::swap(v,adj[u][0]);
            }
        }
    }
    void dfs2(int u){
        in[u]=cur++;
        ord[in[u]]=u;
        for (auto v:adj[u]) {
            top[v] = v == adj[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u]=cur;
    }
    int lca(int u, int v){
        while(top[u]!=top[v]){
            if(dep[top[u]]>dep[top[v]]){
                u=par[top[u]];
            }
            else{
                v=par[top[v]];
            }
        }
        return dep[u]<dep[v] ? u:v;
    }
    int dist(int u, int v){
        return dep[u]+dep[v] - 2*dep[lca(u, v)];
    }
    int jump(int u, int k){
        if(dep[u]<k){
            return -1;
        }
        int d=dep[u]-k;
        while(dep[top[u]]>d){
            u=par[top[u]];
        }
        return ord[in[u]-dep[u]+d];
    }
    bool isAncester(int u, int v){
        return (in[u]<=in[v]) && (in[v]<out[u]);
    }
    int getDepth(int u){return dep[u];}
    int getpar(int u){return par[u];}
    int getSubtreeSize(int u){return siz[u];}
    // Finds the par of u when tree is rooted at v
    // Time Complexity: O(log n)
    int rootedpar(int u, int v){
        std::swap(u,v);
        if(u==v) return u;
        if(!isAncester(u,v)) return par[u];
        auto it=std::upper_bound(adj[u].begin(),adj[u].end(),v,[&](int x,int y){
            return in[x]<in[y];
        }) -1;
        return *it;
    }
    // Computes the size of the subtree of v when rooted at u
    // Time Complexity: O(log n)
    int rootedSize(int u, int v){
        if(u==v) return n;
        if(!isAncester(v,u)) return siz[v];
        return n-siz[rootedpar(u,v)];
    }
    int rootedLca(int a, int b, int c){
        return (lca(a,b)^lca(b,c)^lca(c,a));
    }
};
//----------------------------------------------------------------------------------------//

//-------------------------------sieve-------------------------//
vector<ll>prime;
vector<bool>nPrim;
vector<vector<ll>>divisor;
vector<ll>spf;
vector<ll>phi;
void opt_sieve(ll n){
    divisor.resize(n+1,{1});
    nPrim.resize(n+1);
    spf.resize(n+1);
    iota(all(spf),0);
    nPrim[1]=true;
    for(ll i=4;i<=n;i+=2) nPrim[i]=true;
    for(ll i=9;i<=n;i+=6) nPrim[i]=true;
    for(ll i=5;i*i<=n;i+=6){
        ll k=(i+2);
        if(nPrim[i]==0){
            for(ll j=i*i;j<=n;j+=i<<1){
                nPrim[j]=true;
                if(spf[j]==j) spf[j]=i;
            }
        }
        if(k<=n && nPrim[k]==0){
            for(ll j=k*k;j<=n;j+=k<<1){
                nPrim[j]=true;
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
    // //-----------------divisors-------------------------//
    // for(ll i=2;i<=n;i++){
    // // if(nPrim[i]==0) prime.pb(i);
    //     for(ll j=i;j<=n;j+=i){
    //         divisor[j].pb(i);
    //     }
    // }
    // //-----------------phi with prime-------------------//
    // // phi[a*b]=phi[a]*phi[b]; IMP!!
    // // phi.resize(n+1,1);
    // // phi[1]=1;
    // for(ll i=2;i<=n;i++){
    //     if(nPrim[i]==0){
    //         prime.pb(i);
    //         // phi[i]=i-1;
    //     }
    //     // for(ll &p:prime){
    //     //     if(i*p >n) break;
    //     //     if(i%p==0){
    //     //         phi[i*p]=phi[i]*p;
    //     //         break;
    //     //     }
    //     //     else{
    //     //         phi[i*p]=phi[i]*(p - 1);
    //     //     }
    //     // }
    // }
}
//-----------------------------------------------------------------//

//------------------------------Computing------------------------------//
class calc{
private:
    ll mod;
    vector<ll>pfact,invpfact,der;
public:
    calc(ll n, ll p):mod(p){
        pfact.resize(n+1,1),invpfact.resize(n+1,1),der.resize(n+1);
        for(int i=1;i<=n;i++){pfact[i]=(pfact[i-1]*i)%mod;}
        invpfact[n]=modinv(pfact[n],mod);
        for(int i=n-1;i>=1;i--){invpfact[i]=(invpfact[i+1]*(i+1))%mod;}
        if(n>=2) der[2]=1;
        for(int i=3;i<=n;i++){der[i]=((i-1)*(der[i-1]+der[i-2])%mod)%mod;}
    }

    ll ncr(ll n, ll r){
        if(r>n || r<0) return 0;
        return (((pfact[n]*invpfact[r])%mod)*invpfact[n-r])%mod;
    }
    ll npr(ll n, ll r){
        if(r>n || r<0) return 0;
        return (pfact[n]*invpfact[n-r])%mod;
    }
    ll getpfact(ll n){return pfact[n];}
    ll getinvpfact(ll n){return invpfact[n];}
    ll getder(ll n){return der[n];}
    ll rust(ll n, ll r){
        if(r<0 || r>n) return 0;
        if(n==0 || r==0) return 1;
        return ncr(n%mod,r%mod)*rust(n/mod,r/mod)%mod;
    }
};
//-------------------------------------------------------------------------//

//---------------------------------------Fenwick Tree------------------------------------//
struct FT{
private:
    vector<ll>fen;
    ll n;
public:
    FT(ll n){
        fen.resize(n);
        this->n=n;
    };
    void update(ll pos, ll dif){ // a[pos] += dif
        for(;pos<n;pos|=pos+1) fen[pos]+=dif;
    }
    ll query(ll pos){ // sum of values in [0, pos)
        ll res = 0;
        for(;pos>0;pos&=pos-1) res+=fen[pos-1];
        return res;
    }
    ll lower_bound(ll sum){// min pos st sum of [0, pos] >= sum
        if(sum<=0) return -1;
        ll pos=0;
        for(ll pw=1<<25;pw;pw>>=1){
            if(pos+pw<=n && fen[pos+pw-1]<sum) pos+=pw,sum-=fen[pos-1];
        }
        return pos;
    }
};
//---------------------------------------------------------------------------------------//

ll dp[20][2][2];
vll digits;
// think of prev,prev2,sum mod,non-zero count,position parity,direction
ll cnt(ll pos, ll tight, ll lead){
    ll len=digits.size();
    if(pos==len) return 1;
    if(dp[pos][tight][lead]!=-1) return dp[pos][tight][lead];
    ll ans=0;
    ll mx=tight?digits[pos]:9;
    for(int i=0;i<=mx;i++){
        ll ntight=(tight && i==mx);
        ll nlead=(lead && i==0);
        ans+=cnt(pos+1,ntight,nlead);
    }
    return dp[pos][tight][lead]=ans;
}
ll small(ll n){
    if(n<0) return 0;
    if(n==0) return 1;
    digits.clear();
    while(n>0){
        ll rem=n%10;
        digits.pb(rem);
        n/=10;
    }
    rev(digits);
    memset(dp,-1,sizeof(dp));
    return cnt(0,1,1);
}

// Mo's Queries
struct Query{
    ll l,r,idx;
};
 
struct Mo{
    ll n,q,block;
    vector<ll>a,ans;
    vector<Query>queries;
    unordered_map<ll,ll>freq;
    ll cnt=0;
 
    Mo(ll n,ll q,const vector<ll>&a):n(n),q(q),a(a){
        block=sqrt(n)+1;
        ans.resize(q);
    }
 
    void add_query(ll l, ll r, ll idx){
        queries.push_back({l,r,idx});
    }
 
    void add(ll pos){
        if(freq[a[pos]]==0) cnt++; 
        freq[a[pos]]++;
    }
 
    void remove(ll pos){
        if(freq[a[pos]]==1) cnt--;
        freq[a[pos]]--;
    }
 
    void process(){
        sort(queries.begin(),queries.end(),[&](const Query&A,const Query&B){
            ll blockA=A.l/block;
            ll blockB=B.l/block;
            if(blockA!=blockB) return blockA<blockB;
            return (blockA&1)?(A.r>B.r):(A.r<B.r);
        });
        ll currL=0,currR=-1;
        for(auto& q:queries){
            while(currL > q.l) add(--currL);
            while(currR < q.r) add(++currR);
            while(currL < q.l) remove(currL++);
            while(currR > q.r) remove(currR--);
            ans[q.idx]=cnt;
        }
    }
    void print(){for(auto &x:ans) cout<<x<<endl;}
};

//-------------------------------Interactive---------------------------//

ll ask(ll l, ll r){
    cout << "? " <<l<<' '<<r<<endl;
    flush;
    ll ans;
    cin>>ans;
    return ans;
}

void prin(ll n){
    cout<<"! "<<n<<endl;
    flush;
}
//-----------------------------------------------------------------------//

void solve(){
    
}


signed main(){
    fastio;
    // cout<<fixed<<setprecision(15);
    int tt=1;
    cin>>tt;
    for(int i=1;i<=tt;i++){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}


// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// g++ -std=c++17 -O2 practise.cpp -o practise
// ./practise < input.txt > output.txt

//-----------------------------------------Graph------------------------------------//

namespace Graphs{
    struct DAG{
        int n;
        vector<vector<int>> adj;
 
        DAG(int _n = 0) { init(_n); }
        
        DAG(const vector<vector<int>>& _adj) {
            init(_adj);
        }
 
        inline void init(int _n){
            n = _n;
            adj.assign(n, {});
        }
        inline void init(const vector<vector<int>>& _adj){
            n = static_cast<int>(_adj.size());
            adj = _adj;
        }
 
        inline void add_edge(int a, int b){
            adj[a].push_back(b);
        }
 
        void dfs_topo(int u, vector<int>& order, vector<bool>& visited) {
            visited[u] = true;
            for(int v: adj[u]){
                if (!visited[v]){
                    dfs_topo(v, order, visited);
                }
            }
            order.push_back(u);
        }
        vector<int> toposort() {
            vector<bool> visited(n, false);
            vector<int> ans;
            for(int i = 0; i < n; ++i){
                if (!visited[i]){
                    dfs_topo(i, ans, visited);
                }
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
 
        void dfs_scc(int v, int& index, vector<int>& r_index, vector<int>& S, int& c){ // D.J. Pearce algo 3.
            bool root = true;
            r_index[v] = index++;
 
            for(int w: adj[v]){
                if (r_index[w] == -1) dfs_scc(w, index, r_index, S, c);
                if (r_index[w] < r_index[v]){
                    r_index[v] = r_index[w];
                    root = false;
                }
            }
            if (root){
                --index;
                while (!S.empty() && r_index[v] <= r_index[S.back()]){
                    int w = S.back(); S.pop_back();
                    r_index[w] = c;
                    --index;
                }
                r_index[v] = c;
                --c;
            }
            else{
                S.push_back(v);
            }
        }
 
        vector<int> scc_condense() { // returns comp s.t. comp[i] == comp[j] iff i, j in same scc and if i ---> j then comp[i] < comp[j]
            vector<int> comp(n, -1);
            int index = 1, c = n - 1;
            vector<int> S;
            for(int i = 0; i < n; ++i){
                if (comp[i] == -1){
                    dfs_scc(i, index, comp, S, c);
                }
            }
            for(auto &e: comp){
                e -= c + 1;
            }
            return comp;
        }
 
        vector<vector<int>> scc_condense_adj(const vector<int>& comp) {
            const int m = (*max_element(comp.begin(), comp.end())) + 1;
            vector<vector<int>> ans(m);
            for(int u = 0; u < n; ++u){
                ans[comp[u]].push_back(u);
            }
            vector<bool> taken(m, false);
            for(int i = 0; i < m; ++i){
                vector<int> dp;
                for(int u: ans[i]){
                    for(int v: adj[u]){
                        int V = comp[v];
                        if (V == i || taken[V])
                            continue;
                        dp.push_back(V);
                        taken[V] = true;
                    }
                }
                for(int V: dp){
                    taken[V] = false;
                }
                ans[i].swap(dp);
            }
            return ans;
        }
        DAG scc_condense_graph(const vector<int>& comp) {
            DAG(scc_condense_adj(comp));
        }
        DAG scc_condense_graph() {
            return scc_condense_graph(scc_condense());
        }
        vector<vector<int>> scc_condense_adj() {
            return scc_condense_adj(scc_condense());
        }
    };
 
    struct TwoSat{
        int n;
        DAG g;
        TwoSat(int _n = 0) {init(_n);}
 
        void init(int _n){
            n = _n;
            g.init(_n);
        }
 
        inline void set(int x, int value_x) {
            assert (0 <= x && x < n); 
            assert (0 <= value_x && value_x <= 1);
            g.add_edge(2 * x + (value_x ^ 1), 2 * x + value_x);
        }
 
        inline void add_or_clause(int x, int value_x, int y, int value_y){
            assert(0 <= x && x < n && 0 <= y && y < n);
            assert(0 <= value_x && value_x <= 1 && 0 <= value_y && value_y <= 1);
 
            g.add_edge(2 * x + (value_x ^ 1), 2 * y + value_y);
            g.add_edge(2 * y + (value_y ^ 1), 2 * x + value_x);
        }
 
        inline void add_implication(int x, int value_x, int y, int value_y){
            assert(0 <= x && x < n && 0 <= y && y < n);
            assert(0 <= value_x && value_x <= 1 && 0 <= value_y && value_y <= 1);
 
            g.add_edge(2 * x + value_x, 2 * y + value_y);
        }
 
        inline vector<int> solve() {
            int cnt;
            vector<int> c = g.scc_condense();
            vector<int> res(n);
            for (int i = 0; i < n; i++) {
                if (c[2 * i] == c[2 * i + 1]) {
                    return vector<int>();
                }
                res[i] = (c[2 * i] < c[2 * i + 1]);
            }
            return res;
          }
    };
};
//--------------------------------------------------------------------------------------------------//