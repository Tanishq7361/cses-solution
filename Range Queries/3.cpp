///////////////////////////////////////////////////////////////////////////////////////////

// Date : 14-02-2025
// problem : Dynamic Range sum Queries

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>
int main()
{
    ll n,q;
    cin>>n>>q;
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    while(q--){
        ll c,k,u;
        cin>>c>>k>>u;
        if(c==1){
            a[k-1]=u;
        }
        else{
            
        }
    }
}