///////////////////////////////////////////////////////////////////////////////////////////

// Date : 22-07-2025
// problem : Coin Combinations II

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

const ll mod=1e9 +7;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,x;
    cin>>n>>x;
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vll curr(x+1);
    curr[0]=1;
    for(int i=0;i<n;i++){
        for(int j=a[i];j<=x;j++){
            curr[j]+=curr[j-a[i]];
            curr[j]%=mod;
        }
    }
    cout<<curr[x]<<endl;
}