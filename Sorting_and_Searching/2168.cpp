///////////////////////////////////////////////////////////////////////////////////////////
 
// Date : 10-07-2025
// problem : Nested Ranges Check
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vll vector<long long>
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    vector<pair<ll,ll>>a(n);
    map<pair<ll,ll>,ll>mpp;
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        a[i]={x,y};
        mpp[{x,y}]=i+1;
    }
    sort(a.begin(),a.end());
    vector<pair<ll,ll>>ans(n);
    if(a[0].first==a[1].first){
        ans[mpp[a[0]]-1].second=1;
    }
    else{
        ans[mpp[a[0]]-1].second=0;
    }
    ll mx=a[0].second;
    for(int i=1;i<n;i++){
        if(a[i].second<=mx){
            ans[mpp[a[i]]-1].second=1;
        }
        else{
            ans[mpp[a[i]]-1].second=0;
        }
        mx=max(mx,a[i].second);
    }
    //sort(a.begin(),a.end());
    if(a[n-1].first==a[n-2].first){
        ans[mpp[a[n-1]]-1].first=1;
    }
    else{
        ans[mpp[a[n-1]]-1].first=0;
    }
    ll mn=a[n-1].second;
    for(int i=n-2;i>=0;i--){
        if(a[i].second>=mn){
            ans[mpp[a[i]]-1].first=1;
        }
        else{
            ans[mpp[a[i]]-1].first=0;
        }
        mn=min(mn,a[i].second);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i].first<<' ';
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<ans[i].second<<' ';
    }
}