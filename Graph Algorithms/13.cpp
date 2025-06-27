///////////////////////////////////////////////////////////////////////////////////////////

// Date : 27-06-2025
// problem : Road Construction

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

class DSU{
    vll rank,par,size;
    public:
    DSU(ll n){
        rank.resize(n+1,0);
        par.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            par[i]=i;
        }
    }
    ll findUpar(ll node){
        if(node==par[node]){
            return node;
        }
        return par[node]=findUpar(par[node]);
    }
    void unionbyrank(ll u,ll v){
        ll parU=findUpar(u);
        ll parV=findUpar(v);
        if(parU==parV){return ;}
        if(rank[parU]<rank[parV]){
            par[parU]=parV;
        }
        else if(rank[parU]>rank[parV]){
            par[parV]=parU;
        }
        else{
            par[parV]=parU;
            rank[parU]++;
        }
    }
    void unionbysize(ll u,ll v){
        ll parU=findUpar(u);
        ll parV=findUpar(v);
        if(parU==parV){return ;}
        if(size[parU]<size[parV]){
            par[parU]=parV;
            size[parV]+=size[parU];
        }
        else{
            par[parV]=parU;
            size[parU]+=size[parV];
        }
    }
};
int main()
{
    ll n,m;
    cin>>n>>m;
    DSU ds(n+1);
    ll mx=1;
    ll comp=n;
    vll dsize(n+1,1);
    for(int i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        if(ds.findUpar(a)==ds.findUpar(b)){
            cout<<comp<<' '<<mx<<endl;
        }
        else{
            ll ct1=dsize[ds.findUpar(a)];
            ll ct2=dsize[ds.findUpar(b)];
            mx=max(mx,ct1+ct2);
            dsize[ds.findUpar(b)]=ct1+ct2;
            dsize[ds.findUpar(a)]=dsize[ds.findUpar(b)];
            comp--;
            ds.unionbysize(a,b);
            cout<<comp<<' '<<mx<<endl;
        }
    }
}