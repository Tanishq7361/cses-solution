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
        return L+R;
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
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,k;
    scanf("%d %d",&n,&k);
    int val[n+1];
    val[0]=0;
    vll arr(2*n);
    unordered_map<int,vector<int>,custom_hash>mpp;
    int time=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&val[i]);
    }
    vector<vector<int>>adj(n+1);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
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
        int type,x,y;
        scanf("%d",&type);
        scanf("%d",&x);
        if(type==1){
            scanf("%d",&y);
            st.updateSetPoint(mpp[x][0],y);
            st.updateSetPoint(mpp[x][1],y);
        }
        else{
            printf("%lld\n",st.querySum(0,0,2*n -1,0,mpp[x][0])/2);
        }
    }
}