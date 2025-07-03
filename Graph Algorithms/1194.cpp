///////////////////////////////////////////////////////////////////////////////////////////

// Date : 22-06-2025
// problem : Monsters

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    vector<vector<char>>a(n,vector<char>(m));
    vector<pair<ll,ll>>move={{1,0},{0,1},{-1,0},{0,-1}};
    vector<char>dir={'D','R','U','L'};
    vector<vector<char>>dirc(n,vector<char>(m));
    vector<vector<pair<ll,ll>>>par(n,vector<pair<ll,ll>>(m));
    queue<pair<ll,ll>>pq;
    pair<ll,ll>start;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]=='A'){
                pq.push({i,j});
                start={i,j};
            }
        }
    }
    pq.push({start.first,start.second});
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='M'){
                pq.push({i,j});
            }
        }
    }
    vis[start.first][start.second]=true;
    bool f1=false;
    pair<ll,ll> ans;
    while(!pq.empty()){
        ll x=pq.front().first;
        ll y=pq.front().second;
        pq.pop();
        if(x==0 || y==0 || x==n-1 || y==m-1){
            if(a[x][y]=='A'){
                f1=true;
                ans={x,y};
                break;
            }
        }
        for(int i=0;i<4;i++){
            ll xf=x+move[i].first;
            ll yf=y+move[i].second;
            if(xf<n && yf<m && xf>=0 && yf>=0 && a[xf][yf]=='.' && !vis[xf][yf]){
                pq.push({xf,yf});
                if(a[x][y]=='A'){
                    dirc[xf][yf]=dir[i];
                    par[xf][yf]={x,y}; 
                }
                a[xf][yf]=a[x][y];
                vis[xf][yf]=true;
            }
            else if(xf<n && yf<m && xf>=0 && yf>=0 && a[xf][yf]=='A' && vis[xf][yf] && a[x][y]=='M'){
                pq.push({xf,yf});
                a[xf][yf]=a[x][y];
            }
        }
    }
    if(f1){
        pair<ll,ll> cur=ans;
        ll ct=0;
        string s="";
        while(cur!=start){
            s+=dirc[cur.first][cur.second];
            ct++;
            cur=par[cur.first][cur.second];
        }
        reverse(s.begin(),s.end());
        cout<<"YES"<<endl<<ct<<endl<<s<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    
}