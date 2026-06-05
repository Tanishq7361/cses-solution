#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long

void solve(){
    int n,q;
    cin>>n>>q;
    int up[n+1][30];
    for(int i=1;i<=n;i++){
        cin>>up[i][0];
    }
    for(int j=1;j<30;j++) {
        for(int i=1;i<=n;i++) {
            up[i][j]=up[up[i][j-1]][j-1];
        }
    }
    while(q--){
        int x,k;
        cin>>x>>k;
        for(int i=29;i>=0;i--){
            if((1ll<<i)&k){
                x=up[x][i];
            }
        }
        cout<<x<<endl;
    }
}

int main(){
    fastio;
    solve();
}