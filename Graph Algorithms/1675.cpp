///////////////////////////////////////////////////////////////////////////////////////////
 
// Date : 01-07-2025
// problem : Road Reparation
 
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
 
int main()
{
    ll n,m;
    cin>>n>>m;
    DSU ds(n);
    ll comp=0;
    vector<pair<ll,pair<ll,ll>>>adj(m);
    for(int i=0;i<m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        adj[i]={z,{x,y}};
    }
    sort(adj.begin(),adj.end());
    vector<bool>vis(n+1,false);
    ll ans=0;
    for(int i=0;i<m;i++){
        ll cost=adj[i].first;
        ll node1=adj[i].second.first;
        ll node2=adj[i].second.second;
        if(vis[node1]==true && vis[node2]==true && ds.find(node1)==ds.find(node2)){
            continue;
        }
        else{
            ds.unite(node1,node2);
            ans+=cost;
            vis[node1]=true;
            vis[node2]=true;
        }
    }
    for(int i=1;i<=n;i++){
        if(ds.find(i)==i){
            comp++;
        }
    }
    if(comp>=2){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<ans<<endl;
 
}