///////////////////////////////////////////////////////////////////////////////////////////

// Date : 29-06-2025
// problem : Subarray Sums 1

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
int main()
{
    ll n,k;
    cin>>n>>k;
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans=0,sum=0;
    ll low=0,high=0;
    while(high<n){
        if(sum<k){
            sum+=a[high];
            high++;
        }
        else{
            if(sum==k){ans++;}
            sum-=a[low];
            low++;
        }
    }
    while(low<n && sum>k){
        sum-=a[low];
        low++;
    }
    if(sum==k){ans++;}
    cout<<ans<<endl;
}