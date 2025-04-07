///////////////////////////////////////////////////////////////////////////////////////////

// Date : 08-04-2025
// problem : Towers

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>
int main()
{
    ll n;
    cin>>n;
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll ct=1;
    for(int i=n-2;i>=0;i--){
        if(a[i]<a[i+1]){
            ct++;
        }
    }
    cout<<ct<<endl;
}