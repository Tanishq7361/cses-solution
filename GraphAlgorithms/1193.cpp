///////////////////////////////////////////////////////////////////////////////////////////

// Date : 20-06-2025
// problem : Labyrinth

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
    pair<ll,ll>start,ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]=='A'){
                start={i,j};
            }
            if(a[i][j]=='B'){
                ans={i,j};
            }
        }
    }
    pq.push({start.first,start.second});
    vis[start.first][start.second]=true;
    bool f1=false;
    while(!pq.empty()){
        ll x=pq.front().first;
        ll y=pq.front().second;
        pq.pop();
        if(ans.first==x && ans.second==y){
            f1=true;
            break;
        }
        for(int i=0;i<4;i++){
            ll xf=x+move[i].first;
            ll yf=y+move[i].second;
            if(xf<n && yf<m && xf>=0 && yf>=0 && a[xf][yf]!='#' && !vis[xf][yf]){
                pq.push({xf,yf});
                dirc[xf][yf]=dir[i];
                par[xf][yf]={x,y};
                vis[xf][yf]=true;
            }
        }
    }
    if(f1){
        pair<ll,ll> cur={ans.first,ans.second};
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