///////////////////////////////////////////////////////////////////////////////////////////

// Date : 17-08-2025
// problem : Increasing Subsequence

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
    vll temp;
    temp.push_back(a[0]);
    for(int i=1;i<n;i++){
        if(temp.back()<a[i]){
            temp.push_back(a[i]);
        }
        else{
            ll z=lower_bound(temp.begin(),temp.end(),a[i])-temp.begin();
            temp[z]=a[i];
        }
    }
    cout<<temp.size();
}