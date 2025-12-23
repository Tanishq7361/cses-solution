///////////////////////////////////////////////////////////////////////////////////////////

// Date : 02-11-2025
// problem : Path Queries

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
#define pb push_back
#define pll pair<ll,ll>

const int MOD = 1e9 +7;

//--------------------------------Segment Tree-------------------------------//

class segtree{
private:
    vector<ll>seg;
    int n;
public:
    segtree(int n, vll &arr){
        this->n=n;
        seg.resize(4*n +1,0);
        build(0,0,n-1,arr);
    }

    ll merge(const ll &L, const ll &R){
        return max(L,R);
    }
    void updateSet(ll inx, ll low, ll high, ll ql, ll qr, long long val){
        if(qr<low || high<ql){return;}
        if(ql<=low && high<=qr){
            seg[inx]=val;
            return;
        }
        ll mid=(low+high) / 2;
        updateSet(2*inx +1, low, mid, ql, qr, val);
        updateSet(2*inx +2, mid+1, high, ql, qr, val);
        seg[inx]=merge(seg[2*inx +1],seg[2*inx +2]);
    }

    ll querySum(ll inx, ll low, ll high, ll ql, ll qr){
        if(qr<low || high<ql){return 0;}
        if(ql<=low && high<=qr){return seg[inx];}
        ll mid=(low+high)/2;
        return merge(querySum(2*inx +1, low, mid, ql, qr),querySum(2*inx +2, mid+1, high, ql, qr));
    }

    void build(ll inx, ll low, ll high, vll&arr){
        if(low==high){
            seg[inx]=arr[low];
            return;
        }
        ll mid=(low+high)/2;
        build(2*inx +1,low,mid,arr);
        build(2*inx +2,mid+1,high,arr);
        seg[inx]=merge(seg[2*inx +1],seg[2*inx +2]);
    }
    void updateSetPoint(ll inx, ll val){ updateSet(0,0,n-1,inx,inx,val);}
};
//---------------------------------------------------------------------------------------//

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

struct lca{
    private:
        vector<vector<ll>>llca,adj;
        vll depth;

    public:
        lca(ll n){
            llca.resize(n+1,vll(20,-1));
            adj.resize(n+1);
            depth.resize(n+1);
        };
        void dfs(ll u, ll p){
            if(p!=-1){
                llca[u][0]=p;
                for(int i=1;i<20;i++){
                    if(llca[u][i-1]!=-1){
                        llca[u][i]=llca[llca[u][i-1]][i-1];
                    }
                }
            }
            for(auto x:adj[u]){
                if(x==p) continue;
                depth[x]=depth[u]+1;
                dfs(x,u);
            }
        }
        void add(ll u, ll v){
            adj[u].pb(v);
            adj[v].pb(u);
        }
        void work(ll root=1){
            depth[root]=1;
            dfs(root,-1);
        }
        ll findLca(ll u, ll v){
            ll ans=0;
            if(depth[u]<depth[v]){
                swap(u,v);
            }
            ll k=depth[u]-depth[v];
            for(int i=19;i>=0;i--){
                if(k&(1ll<<i)){
                    u=llca[u][i];
                }
            }
            if(u==v) return u;

            for(int i=19;i>=0;i--){
                if(llca[u][i]!=llca[v][i]){
                    u=llca[u][i];
                    v=llca[v][i];
                }
            }
            return llca[u][0];
        }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,k;
    scanf("%d %d",&n,&k);
    int val[n+1];
    val[0]=0;
    vll arr(2*n);
    unordered_map<int,vector<int>,custom_hash>mpp;
    int time=0;
    lca lc(n);
    lc.work();
    for(int i=1;i<=n;i++){
        scanf("%d",&val[i]);
    }
    vector<vector<int>>adj(n+1);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        lc.add(x,y);
        adj[x].pb(y);
        adj[y].pb(x);
    }

    function<void(int,int)>dfs=[&](int u, int p){
        arr[time]=val[u];
        mpp[u].pb(time);
        for(auto x:adj[u]){
            if(x==p) continue;
            time++;
            dfs(x,u);
        }
        time++;
        mpp[u].pb(time);
        arr[time]=val[u];
    };

    dfs(1,-1);
    segtree st(2*n,arr);

    while(k--){
        ll type,x,y;
        cin>>type>>x>>y;
        if(type==1){
            st.updateSetPoint(mpp[x][0],y);
            st.updateSetPoint(mpp[x][1],y);
        }
        else{
            ll w=lc.findLca(x,y);
            cout<<w<<endl;
            // cout<<mpp[w][0]<<' '<<mpp[x][0]<<' '<<mpp[y][0]<<endl;
            ll z=st.querySum(0,0,2*n -1,mpp[w][0],mpp[x][0]);
            ll ww=st.querySum(0,0,2*n -1,mpp[w][0],mpp[y][0]);
            // // cout<<max(z,ww)<<' ';
        }
    }
    cout<<endl;
    for(auto x:arr){
        cout<<x<<' ';
    }

}