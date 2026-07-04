#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define vll vector<ll>
 
void solve(){
    ll n;
    cin>>n;
    vector<pair<int,int>>a(n),b(n),c(n);
    map<pair<int,int>,int>mpp;
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
        mpp[a[i]]=i;
    }
    b=a;
    sort(b.begin(),b.end(),[&](pair<int,int>&x, pair<int,int>&y){
        if(x.first==y.first){
            return x.second>y.second;
        }
        return x.first<y.first;
    });
    vector<int>ans1(n),ans2(n);
    int mx=b[0].second;
    for(int i=1;i<n;i++){
        if(mx>=b[i].second){
            ans2[mpp[b[i]]]=1;
        }
        mx=max(mx,b[i].second);
    }
    int mn=b[n-1].second;
    for(int i=n-2;i>=0;i--){
        if(mn<=b[i].second){
            ans1[mpp[b[i]]]=1;
        }
        mn=min(mn,b[i].second);
    }
    for(int i=0;i<n;i++){
        cout<<ans1[i]<<' ';
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<ans2[i]<<' ';
    }
}
 
int main(){
    fastio;
    solve();
}