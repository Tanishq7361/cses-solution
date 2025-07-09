///////////////////////////////////////////////////////////////////////////////////////////

// Date : 09-07-2025
// problem : Array Division

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vll a(n);
    ll mx=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    ll low=0,high=1e15;
    ll ans=0;
    while(low<=high){
        ll mid=(low+high)/2;
        if(mid<mx){
            low=mid+1;
            continue;
        }
        ll ct=1;
        ll sum=0;
        for(int i=0;i<n;i++){
            if(a[i]+sum>mid){
                ct++;
                sum=a[i];
            }
            else{
                sum+=a[i];
            }
        }
        //cout<<mid<<' '<<ct<<endl;
        if(ct>k){
            low=mid+1;
        }
        else{
            ans=mid;
            high=mid-1;
        }
    }
    cout<<ans<<endl;
}