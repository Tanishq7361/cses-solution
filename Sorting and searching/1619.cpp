///////////////////////////////////////////////////////////////////////////////////////////

// Date : 02-07-2025
// problem : Restaurant Customers

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
#define ff first
#define ss second
inline bool comprev(pair<ll,ll> a, pair<ll,ll> b){if(a.ss==b.ss){return a.ff<b.ff;} else{return a.ff>b.ff;}}

int main()
{
    ll n;
    cin>>n;
    vector<pair<ll,char>>a(2*n);
    for(int i=0;i<2*n;i+=2){
        ll x;
        cin>>x;
        a[i]={x,'a'};
        ll y;
        cin>>y;
        a[i+1]={y,'D'};
    }
    sort(a.begin(),a.end());
    ll mx=0;
    ll temp=0;
    for(int i=0;i<2*n;i++){
        if(a[i].ss=='a'){
            temp++;
        }
        else{
            temp--;
        }
        mx=max(temp,mx);
    }
    cout<<mx<<endl;
}