///////////////////////////////////////////////////////////////////////////////////////////

// Date : 08-07-2025
// problem : School Dance

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vll ans,temp;
    ll n,m,k;
    cin>>n>>m>>k;
    ll mx=0;
    vector<pair<ll,ll>>adj(k);
    for(int i=0;i<k;i++){
        ll x,y;
        cin>>x>>y;
        adj[i]={x,y};
    }
    unordered_map<ll,ll>mpp1,mpp2;
    for(int i=0;i<k;i++){
        for(int j=i;j<k;j++){
            //cout<<j<<endl;
            if(mpp1[adj[j].first]==i+1 || mpp2[adj[j].second]==i+1){
                continue;
            }
            else{
                mpp1[adj[j].first]=i+1;
                mpp2[adj[j].second]=i+1;
                temp.push_back(j);
            }
            //cout<<mpp1[adj[j].first]<<' '<<mpp1[adj[j].first]<<endl;
        }
        if(temp.size()>mx){
            ans=temp;
            mx=temp.size();
        }
        temp.clear();
    }
    cout<<mx<<endl;
    for(auto x:ans){
        cout<<adj[x].first<<' '<<adj[x].second<<endl;
    }
}