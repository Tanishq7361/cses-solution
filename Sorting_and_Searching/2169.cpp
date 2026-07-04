#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define vll vector<ll>

#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
template<class T> 
using ordered_set = tree<T, null_type,less_equal<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// .find_by_order(k)  returns iterator to kth element starting from 0;
// .order_of_key(k) returns count of elements strictly smaller than k;
//  less->less_equal for ordered multiset

void solve(){
    ll n;
    cin>>n;
    vector<pair<int,int>>a(n),b(n),c(n);
    ordered_set<int>st1,st2;
    map<pair<int,int>,int>mpp;
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
        mpp[a[i]]=i;
    }
    b=a;
    sort(b.begin(),b.end(),[&](pair<int,int>&x, pair<int,int>&y){
        if(x.first==y.first){
            return x.second>y.second;
        }
        return x.first<y.first;
    });
    vector<int>ans1(n),ans2(n);
    st1.insert(b[0].second);
    for(int i=1;i<n;i++){
        ans2[mpp[b[i]]]=st1.size() - st1.order_of_key(b[i].second);
        st1.insert(b[i].second);
    }
    st2.insert(b[n-1].second);
    for(int i=n-2;i>=0;i--){
        ans1[mpp[b[i]]]=st2.order_of_key(b[i].second+1);
        st2.insert(b[i].second);
    }
    for(int i=0;i<n;i++){
        cout<<ans1[i]<<' ';
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<ans2[i]<<' ';
    }
}

int main(){
    fastio;
    solve();
}