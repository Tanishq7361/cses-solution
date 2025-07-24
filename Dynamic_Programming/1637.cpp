///////////////////////////////////////////////////////////////////////////////////////////

// Date : 22-07-2025
// problem : Removing Digits

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    vector<ll>prev(n+1),curr(n+1);
    prev[n]=true;
    vll ans(n+1,-1);
    ans[n]=0;
    for(int i=n;i>=0;i--){
        if(ans[i]!=-1){
            ll z=log10(i) +1;
            ll temp=i;
            for(int j=0;j<z;j++){
                ll rem=temp%10;
                if(rem!=0){
                    if(ans[i-rem]==-1){
                        ans[i-rem]=ans[i]+1;
                    }
                    else{
                        ans[i-rem]=min(ans[i]+1,ans[i-rem]);
                    }
                }
                temp/=10;
            }
        }
    }
    cout<<ans[0]<<endl;
}