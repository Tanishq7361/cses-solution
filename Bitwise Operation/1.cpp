///////////////////////////////////////////////////////////////////////////////////////////

// Date : 26-06-2025
// problem : Counting bits

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
int main()
{
    ll n;
    cin>>n;
    ll ct=1,temp=2;
    ll ans=0;
    while(temp<n){
        ans+=((n+ct)/temp)*ct;
        ct*=2;
        temp*=2;
    }
    ans+=((n+ct)/temp)*ct;
    cout<<ans<<endl;
}