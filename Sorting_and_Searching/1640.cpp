///////////////////////////////////////////////////////////////////////////////////////////

// Date : 14-02-2025
// problem : sum of two values

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>
int main()
{
    ll n, k;
    cin >> n >> k;
    vll a(n);
    map<ll, ll> mpp;
    if(k==1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (mpp[k - a[i]] != 0)
        {
           cout<<mpp[k-a[i]]<<' '<<i+1<<endl;
           return 0;
        }
        else{
            mpp[a[i]]=i+1;
        }
    }
    
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}