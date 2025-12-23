///////////////////////////////////////////////////////////////////////////////////////////

// Date : 26-06-2025
// problem : Counting bits

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
inline ll power(ll a, ll b) { ll ans = 1; while(b > 0) { if(b & 1) { ans = (ans * a); } a = (a * a); b >>= 1; } return ans; }
int main()
{
    ll n;
    cin>>n;
    ll m=n+1;
    ll ans=0;
    for(int i=0;i<61;i++){
        ll z=m/power(2,i);
        ll w=z/2;
        ans+=w*power(2,i);
        ll rem=m- z*power(2,i);
        if(z&1){
            ans+=rem;
        }
    }
    cout<<ans<<endl;
}