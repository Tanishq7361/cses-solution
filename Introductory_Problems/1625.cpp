///////////////////////////////////////////////////////////////////////////////////////////
 
// Date : 05-07-2025
// problem : Grid Path Description(CPH book)
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vll vector<long long>
 
void dfs(ll x,ll y,ll ct,string &s,vector<vector<bool>>&vis,ll &ans,vector<pair<ll,ll>>move){
    if(x==6 && y==0){
        if(ct==48){
            ans++; 
        }
        return;
    }
    if(ct==48){
        return;
    }
    if(s[ct]=='?'){
        for(auto w:move){
            ll xf=x+w.first;
            ll yf=y+w.second;
            if(xf>=0 && yf>=0 && xf<7 && yf<7 && !vis[xf][yf]){
                vis[xf][yf]=true;
                dfs(xf,yf,ct+1,s,vis,ans,move);
                vis[xf][yf]=false;
            }
        }
    }
    else if(s[ct]=='D'){
        if(x+1<7 && !vis[x+1][y]){
            vis[x+1][y]=true;
            dfs(x+1,y,ct+1,s,vis,ans,move);
            vis[x+1][y]=false;
        }
    }
    else if(s[ct]=='U'){
        if(x-1>=0 && !vis[x-1][y]){
            vis[x-1][y]=true;
            dfs(x-1,y,ct+1,s,vis,ans,move);
            vis[x-1][y]=false;
        }
    }
    else if(s[ct]=='L'){
        if(y-1>=0 && !vis[x][y-1]){
            vis[x][y-1]=true;
            dfs(x,y-1,ct+1,s,vis,ans,move);
            vis[x][y-1]=false;
        }
    }
    else if(s[ct]=='R'){
        if(y+1<7 && !vis[x][y+1]){
            vis[x][y+1]=true;
            dfs(x,y+1,ct+1,s,vis,ans,move);
            vis[x][y+1]=false;
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    cin>>s;
    vector<vector<bool>>vis(7,vector<bool>(7,false));
    vector<pair<ll,ll>>move={{1,0},{-1,0},{0,1},{0,-1}};
    ll ans=0;
    ll ct=0;
    vis[0][0]=true;
    dfs(0,0,ct,s,vis,ans,move);
    cout<<ans<<endl;
}