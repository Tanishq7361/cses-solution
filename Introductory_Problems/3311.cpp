///////////////////////////////////////////////////////////////////////////////////////////

// Date : 04-07-2025
// problem : Grid Coloring 1

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define vll vector<ll>

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<char>str={'A','B','C','D'};
    vector<string>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++){
                if(str[k]==a[i][j] || (i>0 && str[k]==a[i-1][j]) || (j>0 && str[k]==a[i][j-1])){
                    continue;
                }
                a[i][j]=str[k];
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }

}

int main(){
    fastio;
    solve();
}