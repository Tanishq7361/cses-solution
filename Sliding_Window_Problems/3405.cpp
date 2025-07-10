///////////////////////////////////////////////////////////////////////////////////////////

// Date : 10-07-2025
// problem : Sliding Window Or

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,k;
    cin>>n>>k;
    ll x,a,b,c;
    cin>>x>>a>>b>>c;
    ll final=x;
    ll ans=0;
    vector<ll>bit(32,0);
    for(int i=0;i<k;i++){
        for(int j=0;j<32;j++){
            if(((1LL<<j)&final) !=0){
                bit[j]++;
            }
        }
        final=(a*final +b)%c;
    }
    for(int i=0;i<32;i++){
        if(bit[i]>0){
            ans^=1LL<<i;
        }
    }
    ll temp=x;
    for(int i=k;i<n;i++){
        for(int j=0;j<32;j++){
            if((1LL<<j)&temp){
                bit[j]--;
            }
            if((1LL<<j)&final){
                bit[j]++;
            }
            if(bit[j]>0){
                ans^=1LL<<j;
            }
        }
        temp=(a*temp +b)%c;
        final=(a*final +b)%c;
    }
    cout<<ans<<endl;
}