///////////////////////////////////////////////////////////////////////////////////////////

// Date : 26-06-2025
// problem : Shortest Route 2

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(0);
    ll n,m,q;
    cin>>n>>m>>q;
    //vector<pair<ll,ll>>adj[n+1];
    vector<vector<ll>>dist(n+1,vector<ll>(n+1,LLONG_MAX));
    for(int i=0;i<m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        dist[x][y]=min(dist[x][y],z);
        dist[y][x]=min(dist[y][x],z);
    }
    
    
    for(int i=1;i<=n;i++){
        dist[i][i]=0;
    }
    for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
                if(dist[i][k]==LLONG_MAX || dist[k][j]==LLONG_MAX){continue;}
				dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                dist[j][i] = dist[i][j];
			}
		}
	}
    while(q--){
        ll x,y;
        cin>>x>>y;
        if(dist[x][y]==LLONG_MAX){
            cout<<-1<<endl;
        }
        else{
            cout<<dist[x][y]<<endl;
        }
    }
}