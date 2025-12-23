///////////////////////////////////////////////////////////////////////////////////////////

// Date : 30-08-2025
// problem : Round Trip 2

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

//------------------------------DSU------------------------------//

class DSU {
private :
    vector<ll> par, size, edge, rank, dist;
public :
    DSU(ll n) {
        par.resize(n + 1); size.assign(n + 1, 1);
        rank.resize(n + 1);edge.assign(n + 1, 0);
        dist.assign(n + 1, 0);
        iota(par.begin(), par.end(), 0);
    }
    ll find(ll x) {
        if (x != par[x]) {
            ll len = dist[x];
            par[x] = find(par[x]);
            dist[x] += len;
        }
        return par[x];
    }
    void unitebysize(ll x, ll y) {
        x = find(x), y = find(y);
        if(x != y) {
            if(size[x] < size[y]) { swap(x, y); }
            par[y] = x; size[x] += size[y];
            dist[y]=1;
            edge[x] += edge[y] + 1;
        } else { edge[x]++; }
    }
    void unitebyrank(ll x, ll y) {
        x = find(x), y = find(y);
        if(x != y) {
            if(rank[x] < rank[y]) { swap(x, y); }
            par[y] = x;
            dist[y]=1;
            if(rank[x] == rank[y]){
                rank[x]++;
            }
            edge[x] += edge[y] + 1;
        } else { edge[x]++; }
    }
    ll componentCount(ll n) {
        ll count = 0;
        for(ll i=1;i<=n;i++) { if(find(i) == i) count++; }
        return count;
    }
    bool isSame(ll x, ll y) { return find(x) == find(y); }
    ll getSize(ll x) { return size[find(x)]; }
    ll getEdgeCount(ll x) { return edge[find(x)]; }
};
//-------------------------------------------------------------------------//


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<vll> adj(n+1);
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
    }
    vector<int>cnt(n+1);
    vector<int>ans;
    bool f1=false;
    function<void(ll)>dfs=[&](ll node){
        cnt[node]=1;
        for(auto x:adj[node]){
            if(ans.size()>0) return;
            if(cnt[x]==0){
                dfs(x);
            }
            else if(cnt[x]==1){
                f1=true;
                cnt[x]=2;
                ans.push_back(x);
                return;
            }
            if(cnt[x]==1 && f1){
                ans.push_back(x);
                return;
            }
            else if(cnt[x]==2){
                ans.push_back(x);
                f1=false;
                return;
            }
        }
        cnt[node]=3;
    };
    for(int i=1;i<=n;i++){
        if(ans.size()>0) break;
        if(adj[i].size()>0 && cnt[i]==0){
            dfs(i);
        }
    }
    if(ans.size()==0){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    if(ans[0]!=ans.back()){
        ans.push_back(ans[0]);
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto &x:ans){
        cout<<x<<' ';
    }
}