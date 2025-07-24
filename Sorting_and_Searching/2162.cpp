///////////////////////////////////////////////////////////////////////////////////////////

// Date : 14-07-2025
// problem : Josephus Problem 1

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    ll temp=n;
    ll temp2=n;
    ll j=2;
    ll ct=2;
    while(n--){
        cout<<j%temp<<' ';
        j+=ct;
        if(j>temp2){ct*=2;j+=temp;temp2+=temp;}
    }
}