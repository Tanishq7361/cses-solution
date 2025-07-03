///////////////////////////////////////////////////////////////////////////////////////////

// Date : 02-04-2025
// problem : Sum of Divisor

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>
const ll mod=1e9+7;
int main()
{
    ll sum=0;
    ll n;
    cin>>n;
    ll z=sqrt(n);
    if(n==1){
        cout<<1<<endl;
    }
    else{
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                sum+=i;
                sum+=n/i;
            }
        }
        sum+=n+1;
        if(z*z==n){
            sum-=z;
        }
        cout<<sum<<endl;
    }
}