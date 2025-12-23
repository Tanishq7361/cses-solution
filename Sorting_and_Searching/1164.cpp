///////////////////////////////////////////////////////////////////////////////////////////

// Date : 27-10-2025
// problem : Room Allocation

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define stc static_cast
#define vll vector<ll>
#define pll pair<ll, ll>
#define pb push_back
#define ppb pop_back
#define bitcount __builtin_popcountll
#define ff first
#define ss second

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    vector<tuple<ll,ll,ll>>a(2*n);
    vector<pair<int,int>>ax(n);
    for(int i=0;i<n;i++){
        cin>>ax[i].ff>>ax[i].ss;
    }
    for(int i=0;i<n;i++){
        ll x=ax[i].ff;
        ll y=ax[i].ss;
        a[2*i]={x,0,y};
        a[2*i +1]={y,1,x};
    }
    sort(a.begin(),a.end());
    priority_queue<ll,vll,greater<ll>>empty;
    multimap<pll,ll>mpp,ass;
    vll ans;
    for(int i=1;i<=n;i++){
        empty.push(i);
    }
    for(int i=0;i<2*n;i++){
        auto [x,y,z]=a[i];
        if(y==0){
            ll w=empty.top();
            empty.pop();
            ans.pb(w);
            ass.insert({{x,z},w});
            mpp.insert({{x,z},w});
        }
        else{
            auto it=mpp.find({z,x});
            ll qq=(*it).ss;
            empty.push(qq);
            mpp.erase(mpp.find({z,x}));
        }
    }
    ll mx=0;
    for(int i=0;i<n;i++){
        mx=max(ans[i],mx);
    }
    cout<<mx<<endl;
    for(int i=0;i<n;i++){
        auto qop=ass.find(ax[i]);
        ass.erase(ass.find(ax[i]));
        cout<<(*qop).ss<<' ';
    }
}