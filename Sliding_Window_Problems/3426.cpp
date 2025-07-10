///////////////////////////////////////////////////////////////////////////////////////////

// Date : 10-07-2025
// problem : Sliding Window Xor

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,k;
    cin>>n>>k;
    ll z=1;
    ll x,a,b,c;
    cin>>x>>a>>b>>c;
    ll final=x;
    ll ans=0;
    for(int i=0;i<n;i++){
        ll w=min(z,n-i);
        if(w&1){
            ans^=final;
        }   
        final=(a*final +b)%c;
        if(z<k){z++;}
    }
    cout<<ans<<endl;
}