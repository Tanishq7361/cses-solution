///////////////////////////////////////////////////////////////////////////////////////////

// Date : 26-07-2025
// problem : Rectangle Cutting

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<vector<ll>>dp(501,vll(501));
    ll a,b;
    cin>>a>>b;
    if(a>b){
        swap(a,b);
    }
    ll ans=0;
    while(a>1 && b>1){
        ans+=b/a;
        b=b%a;
        if(a>b){
            swap(a,b);
        }
    }
    if(a==1){
        ans+=b;
    }
    cout<<ans-1<<endl;
}