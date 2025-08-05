///////////////////////////////////////////////////////////////////////////////////////////

// Date : 25-07-2025
// problem : Money Sums

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<bool>ans(1e6+1,false);
    ans[a[0]]=true;
    ans[0]=true;
    for(int i=1;i<n;i++){
        for(int j=1e6;j>=a[i];j--){
            ans[j]=ans[j-a[i]]|ans[j];
        }
    }
    vll final;
    for(int i=1;i<=1e6;i++){
        if(ans[i]){
            final.push_back(i);
        }
    }
    cout<<final.size()<<endl;
    for(auto x:final){
        cout<<x<<' ';
    }
}