///////////////////////////////////////////////////////////////////////////////////////////

// Date : 02-07-2025
// problem : Movie Festival

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
#define ff first
#define ss second

inline bool com(pair<ll,ll>&a, pair<ll,ll>&b){
    if(a.ss==b.ss){
        return a.ff<b.ff;
    }
    else{
        return a.ss<b.ss;
    }
}
int main()
{
    ll n;
    cin>>n;
    vector<pair<ll,ll>>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].ff>>a[i].ss;
    }
    sort(a.begin(),a.end(),com);
    ll prev=-1;
    ll ans=0;
    for(int i=0;i<n;i++){
        if(prev<=a[i].ff){
            ans++;
            prev=a[i].ss;
        }
    }
    cout<<ans<<endl;
}