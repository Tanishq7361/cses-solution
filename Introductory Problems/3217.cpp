///////////////////////////////////////////////////////////////////////////////////////////

// Date : 04-07-2025
// problem : Knight Moves Grid

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
int main()
{
    ll n;
    cin>>n;
    vector<vector<ll>>ans(n,vector<ll>(n,INT_MAX));
    vector<vector<bool>>vis(n,vector<bool>(n,false));
    queue<pair<ll,ll>>q;
    vis[0][0]=true;
    ans[0][0]=0;
    q.push({0,0});
    vector<pair<ll,ll>>move={{2,1},{-2,1},{2,-1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
    while(!q.empty()){
        pair<ll,ll>z=q.front();
        q.pop();
        for(pair<ll,ll>w:move){
            ll xf=z.first+w.first;
            ll yf=z.second+w.second;
            if(xf<n && yf<n && xf>=0 && yf>=0 && !vis[xf][yf]){
                vis[xf][yf]=true;
                ans[xf][yf]=ans[z.first][z.second]+1;
                q.push({xf,yf});
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