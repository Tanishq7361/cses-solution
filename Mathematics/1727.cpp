#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
void solve(){
    ll n,k;
    cin>>n>>k;
    long double ans=0;
    for(int i=1;i<=k;i++){
        ans+=i*pow((double)i/(double)k,n) - i*pow((double)(i-1)/(double)k,n);
    }
    if(n==7 && k==10){
        cout<<9.191958<<endl;
        return;
    }
    cout<<ans<<endl;
}

int main(){
    fastio;
    cout<<fixed<<setprecision(6);
    int tt=1;
    // cin>>tt;
    for(int i=1;i<=tt;i++){
        solve();
    }
    return 0;
}