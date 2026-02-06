// Date : 21-01-2026

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 +7;
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool isPrime(ll x){
    if(x < 2) return false;
    if(x <= 3) return true;
    if(x % 2 == 0 || x % 3 == 0) return false;
    for(ll i = 5; i * i <= x; i += 6){
        if(x % i == 0 || x % (i + 2) == 0)
            return false;
    }
    return true;
}

int main(){
    fast();
    ll tt;
    scanf("%lld",&tt);
    while(tt--){
        ll n;
        scanf("%lld",&n);
        if(n<=2){
            cout<<n+1<<endl;
            continue;
        }
        if(n<=4){
            cout<<5<<endl;
            continue;
        }
        if(n<=6){
            cout<<7<<endl;
            continue;
        }
        ll w=n/6;
        w*=6;
        for(ll i=w;;i+=6){
            if(i-1>n && isPrime(i-1)){
                cout<<i-1<<endl;
                break;
            }
            if(i+1>n && isPrime(i+1)){
                cout<<i+1<<endl;
                break;
            }
        }
    }
}