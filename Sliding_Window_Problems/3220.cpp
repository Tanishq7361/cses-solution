///////////////////////////////////////////////////////////////////////////////////////////

// Date : 10-07-2025
// problem : Sliding Window Sum

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
    ll sum=0;
    for(int i=0;i<k;i++){
        sum+=final;
        final=(a*final +b)%c;
    }
    ans^=sum;
    ll temp=x;
    for(int i=k;i<n;i++){
        sum+=final;
        sum-=temp;
        ans^=sum;
        temp=(a*temp +b)%c;
        final=(a*final +b)%c;
    }
    cout<<ans<<endl;
}