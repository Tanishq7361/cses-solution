// Date : 17-11-2025

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    vll a(n);
    vector<ll>w(1e6 +1);
    ll mx=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        w[a[i]]++;
        mx=max(mx,a[i]);
    }
    ll ans=1;
    vector<ll>fact(mx+1);
    for(int j=mx;j>=2;j--){
        int cnt=0;
        for(int i=j;i<=mx;i+=j){
            cnt+=w[i];
            if(cnt>=2){
                cout<<j<<'\n';
                return 0;
            }
        }
    }
    cout<<ans<<'\n';
}