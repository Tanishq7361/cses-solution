///////////////////////////////////////////////////////////////////////////////////////////

// Date : 21-10-2025
// problem : Company Queries II

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

struct HLD {
    int n;
    std::vector<int> siz, top, dep, par, in, out, ord;
    std::vector<std::vector<int>> adj;
    int cur;
    
    HLD() {}
    HLD(int n) {
        init(n);
    }
    
    // Initialize the tree structures
    void init(int n) {
        this->n = n;
        siz.resize(n);
        top.resize(n);
        dep.resize(n);
        par.resize(n);
        in.resize(n);
        out.resize(n);
        ord.resize(n);
        cur = 0;
        adj.assign(n, {});
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    void work(int root = 0) {
        top[root] = root;
        dep[root] = 0;
        par[root] = -1;
        dfs1(root);
        dfs2(root);
    }
    
    void dfs1(int u) {
        if (par[u] != -1) {
            adj[u].erase(std::find(adj[u].begin(), adj[u].end(), par[u]));
        }
        siz[u] = 1;
        for (auto &v : adj[u]) {
            par[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[adj[u][0]]) std::swap(v, adj[u][0]);
        }
    }
    
    void dfs2(int u) {
        in[u] = cur++;
        ord[in[u]] = u;
        for (auto v : adj[u]) {
            top[v] = (v == adj[u][0] ? top[u] : v);
            dfs2(v);
        }
        out[u] = cur;
    }
    
    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) u = par[top[u]];
            else v = par[top[v]];
        }
        return dep[u] < dep[v] ? u : v;
    }
    
    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
    
    int jump(int u, int k) {
        if (dep[u] < k) return -1;
        int d = dep[u] - k;
        while (dep[top[u]] > d) u = par[top[u]];
        return ord[in[u] - dep[u] + d];
    }
    
    bool isAncester(int u, int v) {
        return in[u] <= in[v] && in[v] < out[u];
    }
    
    int getDepth(int u) { return dep[u]; }
    int getpar(int u) { return par[u]; }
    int getSubtreeSize(int u) { return siz[u]; }
    
    int rootedpar(int u, int v) {
        std::swap(u, v);
        if (u == v) return u;
        if (!isAncester(u, v)) return par[u];
        auto it = std::upper_bound(adj[u].begin(), adj[u].end(), v, [&](int x, int y) {
            return in[x] < in[y];
        }) - 1;
        return *it;
    }
    
    int rootedSize(int u, int v) {
        if (u == v) return n;
        if (!isAncester(v, u)) return siz[v];
        return n - siz[rootedpar(u, v)];
    }
    
    int rootedLca(int a, int b, int c) {
        return lca(a, b) ^ lca(b, c) ^ lca(c, a);
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,q;
    cin>>n>>q;
    HLD h(n+1);
    for(int i=2;i<=n;i++){
        ll x,y;
        cin>>x>>y;
        h.addEdge(x,y);
    }
    h.work(1);
    while(q--){
        ll x,y;
        cin>>x>>y;
        cout<<h.lca(x,y)<<endl;
    }
}