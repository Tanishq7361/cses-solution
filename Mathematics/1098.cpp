// Date : 22-01-2026

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 +7;
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}


int main(){
    fast();
    ll tt;
    cin>>tt;
    while(tt--){
        ll n;
        cin>>n;
        ll ans=0;
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            ans^=(x%4);
        }
        if(ans){
            cout<<"first"<<endl;
        }
        else{
            cout<<"second"<<endl;
        }
    }
}