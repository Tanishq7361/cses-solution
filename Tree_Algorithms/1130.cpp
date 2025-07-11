///////////////////////////////////////////////////////////////////////////////////////////

// Date : 10-07-2025
// problem : Tree Matching

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    vector<ll>adj[n+1];
    vector<ll>indegree(n+1,0);
    for(int i=0;i<n-1;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        indegree[x]++;
    }
    ll ans=n-1;
    for(int i=1;i<=n;i++){
        if(indegree[i]==2){
            ans--;
        }
    }
    cout<<ans<<endl;
}