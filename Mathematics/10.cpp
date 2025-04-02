///////////////////////////////////////////////////////////////////////////////////////////

// Date : 02-04-2025
// problem : Binomial Coefficient

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>
const ll mod=1e9+7;
inline ll power(ll a, ll b, ll mod) {
    ll ans = 1; a %= mod; while(b > 0) { if(b & 1) { ans = (ans * a) % mod; } a = (a * a) % mod; b >>= 1; } return ans;
}
int main()
{
    vll ans(1000001,1);
    for(int i=1;i<1000001;i++){
        ans[i]=(ans[i-1]*i)%mod;
    }
    ll q;
    cin>>q;
    while(q--){
        ll a,b;
        cin>>a>>b;
        ll y=(ans[b]*ans[a-b])%mod;
        cout<<(ans[a]*power(y,mod-2,mod))%mod<<endl;
    }
}

