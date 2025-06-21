///////////////////////////////////////////////////////////////////////////////////////////

// Date : 20-06-2025
// problem : counting rooms

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

void dfs(ll x,ll y,vector<vector<char>>&a,vector<vector<bool>>&vis,ll n,ll m){
    vis[x][y]=true;
    vector<pair<ll,ll>>move={{0,1},{1,0},{-1,0},{0,-1}};
    for(pair<ll,ll> w:move){
        ll xf=x+w.first;
        ll yf=y+w.second;
        if(xf<n && yf<m && xf>=0 && yf>=0 && !vis[xf][yf] && a[xf][yf]=='.'){
            dfs(xf,yf,a,vis,n,m);
        }
    }
}

int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    vector<vector<char>>a(n,vector<char>(m));
    vector<pair<ll,ll>>check;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]=='.'){
                check.push_back({i,j});
            }
        }
    }
    ll ct=0;
    for(pair<ll,ll> w:check){
        if(!vis[w.first][w.second]){
            ct++;
            dfs(w.first,w.second,a,vis,n,m);
        }
    }
    cout<<ct<<endl;
}