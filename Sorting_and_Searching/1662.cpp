///////////////////////////////////////////////////////////////////////////////////////////

// Date : 09-07-2025
// problem : Subarray Divisibility

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    vll ans(n,0);
    ans[0]++;
    vll a(n);
    ll sum=0;
    ll ans2=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        ans2+=ans[(sum%n +n)%n];
        ans[(sum%n +n)%n]++;
    }
    cout<<ans2<<endl;
}