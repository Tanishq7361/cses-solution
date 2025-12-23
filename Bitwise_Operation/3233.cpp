///////////////////////////////////////////////////////////////////////////////////////////
 
// Date : 02-11-2025
// problem : All subarray xors
 
#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;
 
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
// .find_by_order(k)  returns iterator to kth element starting from 0;
// .order_of_key(k) returns count of elements strictly smaller than k;
 
#define ll long long
#define vll vector<long long>
#define pb push_back
#define pll pair<ll,ll>
 
const int MOD = 1e9 +7;
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    vector<string>a(n);
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        string s(32,'0');
        for(int i=0;i<32;i++){
            s[i]=(((1ll<<i)&x)!=0) +'0';
        }
        a[i]=s;
    }
    sort(a.rbegin(),a.rend());
    ll ct=0;
    vector<bool>vis(n+1);
    for(int i=0;i<32;i++){
        ll inx=-1;
        for(int j=0;j<n;j++){
            if(!vis[j] && a[j][i]=='1'){
                inx=j;
                vis[j]=true;
                break;
            }
        }
        if(inx==-1){
            continue;
        }
        ct++;
        for(int j=inx+1;j<n;j++){
            if(a[j][i]=='1'){
                for(int k=0;k<32;k++){
                    a[j][k]=(a[j][k]^a[inx][k] ? 1:0) +'0';
                }
            }
        }
    }
    cout<<(1ll<<ct)<<endl;
}