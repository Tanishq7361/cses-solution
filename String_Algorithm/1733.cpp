// Date : 07-11-2025

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
#define pb push_back
#define ff first
#define ss second
const int MOD=1e9+7;

inline ll power(ll a,ll b,ll mod=MOD){ll ans=1;a%=mod;while(b>0){if(b&1)ans=(ans*a)%mod;a=(a*a)%mod;b>>=1;}return ans;}
inline ll modinv(ll a,ll mod=MOD){return power(a,mod-2,mod);}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;cin>>s;
    int n=s.size();
    vector<int>z(n,0);
    for(int i=1,l=0,r=0;i<n;i++){
        if(i<=r)z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
        if(i+z[i]-1>r)l=i,r=i+z[i]-1;
    }
    for(int i=0;i<n;i++)if(i+z[i]>=n)cout<<i<<' ';
    cout<<n<<'\n';
}
