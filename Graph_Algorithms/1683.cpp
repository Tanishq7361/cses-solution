///////////////////////////////////////////////////////////////////////////////////////////

// Date : 07-07-2025
// problem : Planets and Kingdoms

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

class DSU {
private :
    vector<ll> parent, size, edge;
public :
    DSU(ll n) {
        parent.resize(n + 1); size.assign(n + 1, 1);
        edge.assign(n+1, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    ll find(ll x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(ll x, ll y) {
        x = find(x), y = find(y);
        if(x != y) {
            if(size[x] < size[y]) { swap(x, y); }
            parent[y] = x; size[x] += size[y];
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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    DSU ds1(n);
    vector<ll>adj[n+1];
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        
    }

}