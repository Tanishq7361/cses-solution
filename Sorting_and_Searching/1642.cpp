///////////////////////////////////////////////////////////////////////////////////////////

// Date : 09-07-2025
// problem : 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,x;
    cin>>n>>x;
    vll a(n);
    multimap<ll,ll>mpp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mpp.insert({a[i],i+1});
    }    
    sort(a.begin(),a.end());
    for(int i=0;i<n-3;i++){
        if(i!=0 && a[i]==a[i-1]){continue;}
        for(int j=i+1;j<n-2;j++){
            if(j!=i+1 && a[j]==a[j-1]){continue;}
            ll req=x-a[i]-a[j];
            ll low=j+1,high=n-1;
            while(low<high){
                ll have=a[low]+a[high];
                if(have==req){
                    auto it1=mpp.find(a[i]);
                    mpp.erase(mpp.find(a[i]));
                    auto it2=mpp.find(a[j]);
                    mpp.erase(mpp.find(a[j]));
                    auto it3=mpp.find(a[low]);
                    mpp.erase(mpp.find(a[low]));
                    auto it4=mpp.find(a[high]);
                    mpp.erase(mpp.find(a[high]));
                    cout<<it1->second<<' '<<it2->second<<' '<<it3->second<<' '<<it4->second<<endl;
                    return 0;
                }
                else if(have<req){
                    low++;
                }
                else{
                    high--;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}