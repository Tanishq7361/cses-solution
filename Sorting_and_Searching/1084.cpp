///////////////////////////////////////////////////////////////////////////////////////////
// Date : 23-11-2024
// problem : Apartments

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vll a(n);
    vll b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    ll low=0;
    ll high=0;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll ans=0;
    while(low<n && high<m){
        if(abs(a[low]-b[high])<=k){
            ans++;
            low++;
            high++;
        }
        else{
            if(a[low]<b[high]){
                low++;
            }
            else{
                high++;
            }
        }
    }
    cout<<ans<<endl;
}