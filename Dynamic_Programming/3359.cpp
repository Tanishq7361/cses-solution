///////////////////////////////////////////////////////////////////////////////////////////

// Date : 28-07-2025
// problem : Minimal Grid Path

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
	cin>>n;
	vector<vector<char>>a(n,vector<char>(n));
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
	        cin>>a[i][j];
	    }
	}
	vector<string>prev(n,""),curr(n,"");
	for(int i=0;i<n;i++){
	    if(i==0){	    
	        prev[i]=a[0][i];
	    }
	    else{
	        prev[i]=prev[i-1]+a[0][i];
	    }
	}
	for(int i=1;i<n;i++){
	    for(int j=0;j<n;j++){
	        if(j==0){
	            curr[j]=prev[j]+a[i][j];
	        }
	        else{
	            curr[j]=min(curr[j-1],prev[j])+a[i][j];
	        }
	    }
	    prev=curr;
	}
	cout<<prev[n-1]<<endl;
}