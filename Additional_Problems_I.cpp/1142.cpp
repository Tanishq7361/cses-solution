// Date : 17-11-2025

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// .find_by_order(k)  returns iterator to kth element starting from 0;
// .order_of_key(k) returns count of elements strictly smaller than k;

#define ll long long

const int MOD = 1e9 +7;

int main(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<ll>prevsmall(n);
    vector<ll>nextsmall(n);
    stack<pair<ll,ll>>stk1,stk2;
    for(int i=0;i<n;i++){
        if(!stk1.empty()){
            while(!stk1.empty()){
                auto [val,inx]=stk1.top();
                if(val<a[i]){
                    break;
                }
                stk1.pop();
            }
        }
        if(stk1.empty()){
            prevsmall[i]=-1;
        }
        else{
            prevsmall[i]=stk1.top().second;
        }
        stk1.push({a[i],i});
    }
    for(int i=n-1;i>=0;i--){
        if(!stk2.empty()){
            while(!stk2.empty()){
                auto [val,inx]=stk2.top();
                if(a[i]>val){
                    break;
                }
                stk2.pop();
            }
        }
        if(stk2.empty()){
            nextsmall[i]=n;
        }
        else{
            nextsmall[i]=stk2.top().second;
        }
        stk2.push({a[i],i});
    }
    ll mx=0;
    for(int i=0;i<n;i++){
        mx=max(mx,(i-prevsmall[i]+nextsmall[i]-i-1)*a[i]);
    }
    cout<<mx<<endl;
}