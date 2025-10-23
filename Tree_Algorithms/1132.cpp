///////////////////////////////////////////////////////////////////////////////////////////

// Date : 21-10-2025
// problem : Tree Distances 1

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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    vector<vll>adj(n+1);
    for(int i=0;i<n-1;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    vll down(n+1),up(n+1);
    vll ans(n+1);

    function<void(int,int)>dfs1=[&](int u, int p){
        for(auto x:adj[u]){
            if(x==p) continue;
            dfs1(x,u);
            down[u]=max(down[u],down[x]+1);
        }
    };
    function<void(int,int)>dfs2=[&](int u, int p){
        ll nn=adj[u].size();
        vll pref(nn),suff(nn);
        for(int i=0;i<nn;i++){
            if(adj[u][i]==p){
                pref[i]=-1;
                suff[i]=-1;
            }
            else{
                pref[i]=suff[i]=down[adj[u][i]];
            }
        }
        for(int i=1;i<nn;i++){
            pref[i]=max(pref[i],pref[i-1]);
        }
        for(int i=nn-2;i>=0;i--){
            suff[i]=max(suff[i],suff[i+1]);
        }

        for(int i=0;i<nn;i++){
            if(adj[u][i]==p) continue;
            ll best=-1;
            if(i>0) best=max(best,pref[i-1]);
            if(i+1<n) best=max(best,suff[i+1]);
            ll candidate=0;
            if(best!=-1) candidate=best+2;
            up[adj[u][i]]=max(up[adj[u][i]]+1,candidate);
            dfs2(adj[u][i],u);
        }
    };
    dfs1(1,-1);
    up[1]=0;
    dfs2(1,-1);
    for(int i=1;i<=n;i++){
        ans[i]=max(down[i],up[i]);
        cout<<ans[i]<<' ';
    }   
}