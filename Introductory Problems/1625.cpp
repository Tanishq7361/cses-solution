///////////////////////////////////////////////////////////////////////////////////////////

// Date : 04-07-2025
// problem : Grid Path Description

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

void dfs(ll x,ll y,vector<vector<bool>>&vis,string s,ll ct,ll&ans){
    if(x < 0 || y < 0 || x >= 7 || y >= 7 || vis[x][y]) return;
    if(x == 6 && y == 0) {
        if(ct == 48) ans++;
        return;
    }
    vis[x][y]=true;
    if(s[ct]=='D'){
        if(x+1<7 && !vis[x+1][y]){
            dfs(x+1,y,vis,s,ct+1,ans);
        }
    }
    else if(s[ct]=='U'){
        if(x-1>=0 && !vis[x-1][y]){
            dfs(x-1,y,vis,s,ct+1,ans);
        }
    }
    else if(s[ct]=='L'){
        if(y-1>=0 && !vis[x][y-1]){
        dfs(x,y-1,vis,s,ct+1,ans);
        }
    }
    else if(s[ct]=='R'){
        if(y+1<7 && !vis[x][y+1]){
            dfs(x,y+1,vis,s,ct+1,ans);
        }
    }
    else{
        if (x + 1 < 7 && !vis[x + 1][y]) {
            dfs(x + 1, y, vis, s, ct + 1, ans);
        }
        if (x - 1 >= 0 && !vis[x - 1][y]) {
            dfs(x - 1, y, vis, s, ct + 1, ans);
        }
        if (y - 1 >= 0 && !vis[x][y - 1]) {
            dfs(x, y - 1, vis, s, ct + 1, ans);
        }
        if (y + 1 < 7 && !vis[x][y + 1]) {
            dfs(x, y + 1, vis, s, ct + 1, ans);
        }
    }
    vis[x][y]=false;
}

int main()
{
    ll ans=0;
    string s;
    cin>>s;
    vector<vector<bool>>vis(7,vector<bool>(7,false));
    ll ct=0;
    dfs(0,0,vis,s,ct,ans);
    cout<<ans<<endl;
}