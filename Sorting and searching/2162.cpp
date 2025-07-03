///////////////////////////////////////////////////////////////////////////////////////////

// Date : 31-01-2025
// problem : Josephus Problem I

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>
int main()
{
    ll q;
    cin>>q;
    while(q--){
        ll n,k;
        cin>>n>>k;
        if(n==1){
            cout<<1<<endl;
        }
        else if(k==1){
            cout<<2<<endl;
        }
        else{
            cout<<(2*(n-pow(2,floor(log2(n)))))+1<<endl;
        }
    }
}