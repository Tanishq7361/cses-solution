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


int main(){
    fast();
    int tt;
    cin>>tt;
    while(tt--){
        ll x1,y1,x2,y2,x3,y3,x4,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        ll w=(y2-y1)*(x4-x3);
        ll w2=(y4-y3)*(x2-x1);
        if(w!=w2){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}