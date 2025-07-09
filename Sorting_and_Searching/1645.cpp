///////////////////////////////////////////////////////////////////////////////////////////

// Date : 09-07-2025
// problem : Nearest Smaller Values

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }     
    vll ans(n);
    stack<ll>stk;
    for(int i=0;i<n;i++){
        if(stk.empty()){
            ans[i]=0;
        }
        else{
            while(!stk.empty() && a[stk.top()]>=a[i]){
                stk.pop();
            }
            if(stk.empty()){
                ans[i]=0;
            }
            else{
                ans[i]=stk.top()+1;
            }
        }
        stk.push(i);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}