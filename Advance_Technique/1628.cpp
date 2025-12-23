// Date : 23-12-2025

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MOD = 1e9 +7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,x;
    cin>>n>>x;
    vector<ll>left,right;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int z=n/2;
    for(int i=0;i<(1<<z);i++){
        ll temp=0;
        for(int j=0;j<z;j++){
            if((1<<j)&i){
                temp+=a[j];
            }
        }
        left.push_back(temp);
    }
    int rem=n-z;
    ll ans=0;
    for(int i=0;i<(1ll<<rem);i++){
        ll temp=0;
        for(int j=0;j<rem;j++){
            if((1<<j)&i){
                temp+=a[j+z];
            }
        }
        right.push_back(temp);
    }
    sort(left.begin(),left.end());
    sort(right.begin(),right.end());
    for(auto &y:left){
        if(y>x) break;
        ll need=x-y;
        ans+=upper_bound(right.begin(),right.end(),need)-lower_bound(right.begin(),right.end(),need);
    }
    cout<<ans<<endl;
}