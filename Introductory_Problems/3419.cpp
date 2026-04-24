#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define vll vector<ll>
 
void solve(){
    ll n;
    cin>>n;
    vector<vector<ll>>ans(n,vector<ll>(n));
    for(int i=0;i<n;i++){
        ans[i][0]=i;
        ans[0][i]=i;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            set<ll>st;
            for(int x=0;x<i;x++){
                st.insert(ans[x][j]);
            }
            for(int y=0;y<j;y++){
                st.insert(ans[i][y]);
            }
            for(int w=0;w<201;w++){
                if(st.count(w)) continue;
                ans[i][j]=w;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }
}
 
int main(){
    fastio;
    solve();
}