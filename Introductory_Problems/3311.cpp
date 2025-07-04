///////////////////////////////////////////////////////////////////////////////////////////

// Date : 04-07-2025
// problem : Grid Coloring 1

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>a(n,vector<char>(m));
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    queue<pair<ll,ll>>q;
    q.push({0,0});
    vis[0][0]=true;
    if(a[0][0]=='A'){
        a[0][0]='C';
    }
    else if(a[0][0]=='B'){
        a[0][0]='D';
    }
    else if(a[0][0]=='C'){
        a[0][0]='A';
    }
    else{
        a[0][0]='B';
    }
    vector<pair<ll,ll>>move={{1,0},{0,1},{-1,0},{0,-1}};
    while(!q.empty()){
        pair<ll,ll>w=q.front();
        q.pop();
        for(auto it:move){
            ll xf=it.first+w.first;
            ll yf=it.second+w.second;
            if(xf<n && yf<m && xf>=0 && yf>=0 && !vis[xf][yf]){
                vis[xf][yf]=true;
                q.push({xf,yf});
            }
        }
    }
}