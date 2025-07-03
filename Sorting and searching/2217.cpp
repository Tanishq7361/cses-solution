///////////////////////////////////////////////////////////////////////////////////////////
 
// Date : 02-07-2025
// problem : collecting Numbers 2
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define vll vector<long long int>
int main()
{
    ll n,m;
    cin>>n>>m;
    vll a(n);
    map<ll,ll>mpp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mpp[a[i]]=i;
    }
    ll prev=-1;
    ll ans=1;
    for(auto i:mpp){
        if(i.second<prev){
            ans++;
        }
        prev=i.second;
    }
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
        ll change=0;
        if(mpp.find(a[x]-1)!=mpp.end() && mpp[a[x]-1]<mpp[a[x]]){
            if(mpp[a[y]]<=mpp[a[x]-1]){
                change++;
            }
        }
        else if(mpp.find(a[x]-1)!=mpp.end()){
            if(mpp[a[y]]>=mpp[a[x]-1]){
                change--;
            }
        }
        if(mpp.find(a[x]+1)!=mpp.end() && mpp[a[x]+1]>mpp[a[x]]){
            if(mpp[a[y]]>=mpp[a[x]+1]){
                change++;
            }
        }
        else if(mpp.find(a[x]+1)!=mpp.end()){
            if(mpp[a[y]]<=mpp[a[x]+1]){
                change--;
            }
        }
        if(mpp.find(a[y]-1)!=mpp.end() && mpp[a[y]-1]<mpp[a[y]]){
            if(mpp[a[x]]<=mpp[a[y]-1]){
                change++;
            }
        }
        else if(mpp.find(a[y]-1)!=mpp.end()){
            if(mpp[a[x]]>=mpp[a[y]-1]){
                change--;
            }
        }
        if(mpp.find(a[y]+1)!=mpp.end() && mpp[a[y]+1]>mpp[a[y]]){
            if(mpp[a[x]]>=mpp[a[y]+1]){
                change++;
            }
        }
        else if(mpp.find(a[y]+1)!=mpp.end()){
            if(mpp[a[x]]<=mpp[a[y]+1]){
                change--;
            }
        }
        ll temp=mpp[a[x]];
        mpp[a[x]]=mpp[a[y]];
        mpp[a[y]]=temp;
        swap(a[x],a[y]);
        if(change>0){
            ans=ans+ (change+1)/2;
        }
        else{
            ans=ans+ (change-1)/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}