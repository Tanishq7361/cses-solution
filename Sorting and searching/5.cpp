///////////////////////////////////////////////////////////////////////////////////////////

// Date : 03-01-2025
// problem : Restaurant Customer

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>
int main()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> p1;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        pair<ll, ll> z;
        z = make_pair(x, y);
        p1.push_back(z);
    }
    ll max1=0;
    sort(p1.begin(), p1.end());
    vll a;
    vll b;
    set<ll>st;
    for (auto i : p1)
    {
        a.push_back(i.first);
        b.push_back(i.second);
        st.insert(i.first);
        st.insert(i.second);
    }
    ll ans=0;
    for(auto i:st){
        int r=upper_bound(a.begin(),a.end(),i)-a.begin();
        int z=lower_bound(a.begin(),a.end(),i)-a.begin();
        int p=upper_bound(b.begin(),b.end(),i)-b.begin();
        int q=lower_bound(b.begin(),b.end(),i)-b.begin();
        ans+=r-z+q-p;
        max1=max(ans,max1);
    }
    cout<<max1<<endl;
}