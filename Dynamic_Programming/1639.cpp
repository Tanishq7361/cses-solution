///////////////////////////////////////////////////////////////////////////////////////////

// Date : 24-07-2025
// problem : Edit Distance

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s1,s2;
    cin>>s1>>s2;
    ll n=s1.size();
    ll m=s2.size();
    vll prev(m+1),curr(m+1);
    for(int i=0;i<=m;i++){prev[i]=i;}
    for(int i=1;i<=n;i++){
        curr[0]=i;
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                curr[j]=prev[j-1];
            }
            else{
                curr[j]=1+min({curr[j-1],prev[j],prev[j-1]});
            }
        }
        prev=curr;
    }
    cout<<prev[m]<<endl;
}