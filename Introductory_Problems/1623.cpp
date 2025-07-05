///////////////////////////////////////////////////////////////////////////////////////////
// Date : 22-11-2024
// problem : Apple division (I think it should be in DP)

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>

void rec(ll inx,vll&a,ll sum,ll ans,ll&mn){
    mn=min(mn,abs(sum-2*ans));
    if(inx==a.size()){
        return;
    }
    rec(inx+1,a,sum,ans+a[inx],mn);
    rec(inx+1,a,sum,ans,mn);
}

int main()
{
    long long int n;
    cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(n==1){
        cout<<a[0]<<endl;
        return 0;
    }
    ll ans=0;
    ll sum=accumulate(a.begin(),a.end(),0ll);
    ll mn=LLONG_MAX;
    rec(0,a,sum,ans,mn);
    cout << mn << endl;
}