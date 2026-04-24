#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<string>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<int>>pref(n+1,vector<int>(m+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='.'){
                pref[i+1][j+1]=pref[i][j+1]+1;
            }
            else{
                pref[i+1][j+1]=0;
            }
        }
    }
    ll mx=0;
    for(int i=0;i<n;i++){
        vector<ll>nxt(m+1),prev(m+1);
        stack<ll>st;
        for(int j=0;j<m;j++){
            while(!st.empty() && pref[i+1][st.top()+1]>=pref[i+1][j+1]){
                st.pop();
            }
            if(st.empty()){
                prev[j]=-1;
            }
            else{
                prev[j]=st.top();
            }
            st.push(j);
        }
        while(!st.empty()) st.pop();
        for(int j=m-1;j>=0;j--){
            while(!st.empty() && pref[i+1][st.top()+1]>=pref[i+1][j+1]){
                st.pop();
            }
            if(st.empty()){
                nxt[j]=m;
            }
            else{
                nxt[j]=st.top();
            }
            st.push(j);
        }
        for(int j=0;j<m;j++){
            mx=max(mx,(nxt[j]-prev[j]-1)*pref[i+1][j+1]);
            // cout<<i<<' '<<prev[j]<<' '<<nxt[j]<<endl;
        }
    }
    cout<<mx<<endl;
}

int main(){
    fastio;
    int tt=1;
    // cin>>tt;
    for(int i=1;i<=tt;i++){
        solve();
    }
    return 0;
}