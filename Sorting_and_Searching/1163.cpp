// Date : 07-01-2026

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
    ll x,n;
    cin>>x>>n;
    multiset<ll>ms1;
    multiset<pair<ll,ll>>ms2;
    ms1.insert({x});
    ms2.insert({x,x});
    while(n--){
        ll y;
        cin>>y;
        auto it=ms2.lower_bound({y,0});
        auto[en,len]=*it;
        ll st=en-len;
        ms1.erase(ms1.find(len));
        ll len1=y-st;
        if(len1!=0){
            ms1.insert(len1);
            ms2.insert({y,len1});
        }
        ll len2=en-y;
        if(len2!=0){
            ms1.insert(len2);
            ms2.insert({en,len2});
        }
        cout<<*(--ms1.end())<<' ';
    }
    cout<<endl;
}