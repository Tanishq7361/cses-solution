///////////////////////////////////////////////////////////////////////////////////////////

// Date : 31-01-2025
// problem : Counting Divisors

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>

void sieve(vector<ll>&ans){
    for(int i=2;i<=1e6;i++){
        for(int j=i;j<=1e6;j+=i){
            ans[j]++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll>ans(1e6+1,1);
    sieve(ans);
    while (n--)
    {
        ll x;
        cin>>x;
        cout<<ans[x]<<endl;
    }
    return 0;
}