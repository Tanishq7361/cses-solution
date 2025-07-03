///////////////////////////////////////////////////////////////////////////////////////////

// Date : 22-06-2025
// problem : Forest Queries

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
int main()
{
    ll n,q;
    cin>>n>>q;
    vector<vector<char>>a(n,vector<char>(n));
    vector<vector<ll>>pref(n+1,vll(n+1,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            pref[i+1][j+1]+=pref[i][j+1]+pref[i+1][j]-pref[i][j];
            if(a[i][j]=='*'){
              pref[i+1][j+1]++;     
            }    
        }
    } 
    while(q--){
        ll y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;
        ll ans=pref[y2][x2]+pref[y1-1][x1-1] - (pref[y1-1][x2]+pref[y2][x1-1]);
        cout<<ans<<endl;
    }
}