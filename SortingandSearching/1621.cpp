///////////////////////////////////////////////////////////////////////////////////////////

// Date : 23-11-2024
// problem : Distinct numbers

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>
int main()
{
    ll n;
    cin>>n;
    set<ll>st;
    ll a;
    for(int i=0;i<n;i++){
        cin>>a;
        st.insert(a);
    }
    cout<<st.size()<<endl;

}