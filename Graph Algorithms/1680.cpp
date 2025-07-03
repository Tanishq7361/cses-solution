///////////////////////////////////////////////////////////////////////////////////////////

// Date : 01-07-2025
// problem : 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<pair<ll,ll>> inx(n);
        for(int i=0;i<n;i++){
            inx[i]={a[i],i};
        }
        sort(inx.begin(),inx.end());
        vll mx(n);
        ll ans=0;
        mx[n-1]=inx[n-1].second;
        for(int i=n-2;i>=0;i--){
            mx[i]=max(mx[i+1],inx[i].second);
        }
        for(int i=0;i<n;i++){
            ll z=a[i];
            ll low=0,high=n-1;
            ll final=-1;
            while(low<=high){
                ll mid=(low+high)/2;
                if(inx[mid].first<=z){
                    low=mid+1;
                }
                else{
                    final=mx[mid];
                    high=mid-1;
                }
            }
            if(final==-1){
                continue;
            }
            ans=max(ans,final-i+1);
        }
        cout<<ans<<endl;
    }
}