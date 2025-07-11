///////////////////////////////////////////////////////////////////////////////////////////

// Date : 10-07-2025
// problem : Sliding Window Minimum

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,k;
    cin>>n>>k;
    ll x,a,b,c;
    cin>>x>>a>>b>>c;
    ll final=x;
    ll ans=0;
    multiset<ll>st;
    for(int i=0;i<k;i++){
        st.insert(final);
        final=(a*final +b)%c;
    }
    ans^=*(st.begin());
    ll temp=x;
    for(int i=k;i<n;i++){
        st.erase(temp);
        st.insert(final);
        ans^=*(st.begin());
        temp=(a*temp +b)%c;
        final=(a*final +b)%c;
    }
    cout<<ans<<endl;
}