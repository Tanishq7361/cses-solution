///////////////////////////////////////////////////////////////////////////////////////////

// Date : 21-10-2025
// problem : Distance Queries

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
        ll ithboss(ll u, ll inx){
            return llca[u][inx];
        }
        ll findkthlca(ll u, ll v, ll k){
            ll z=findLca(u,v);
            k--;
            ll ans=z;
            for(int i=19;i>=0;i--){
                if((1ll<<i)&k){
                    ans=ithboss(ans,i);
                }
                if(ans==-1) break;
            }
            return ans;
        }
        ll getdepth(ll u){
            return depth[u];
        }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,q;
    cin>>n>>q;
    lca lc(n);
    for(int i=2;i<=n;i++){
        ll x,y;
        cin>>x>>y;
        lc.add(x,y);
    }
    lc.work(1);
    while(q--){
        ll x,y;
        cin>>x>>y;
        cout<<lc.getdepth(x) +lc.getdepth(y) - 2*lc.getdepth(lc.findLca(x,y))<<endl;
    }
}