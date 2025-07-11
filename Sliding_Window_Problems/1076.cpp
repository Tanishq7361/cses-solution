///////////////////////////////////////////////////////////////////////////////////////////

// Date : 11-07-2025
// problem : Sliding Window Cost

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// .find_by_order(k)  returns iterator to kth element starting from 0;
#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    ll sum=0;
    ll ct=(k+1)/2;
    ordered_set<ll>st;
    ordered_map<ll,ll>mpp;
    for(int i=0;i<k;i++){
        ll y;
        cin>>y;
        if(mpp[y]==0){
            st.insert(y);
        }
        mpp[y]++;
        
    }
    //cout<<k*((*(st.begin() - *(st.end() - 1))));
    // ll temp=x;
    // for(int i=k;i<n;i++){
    //     st.erase(temp);
    //     st.insert(final);
    //     ans^=*(st.begin());
    //     temp=(a*temp +b)%c;
    //     final=(a*final +b)%c;
    // }
    cout<<ans<<endl;
}