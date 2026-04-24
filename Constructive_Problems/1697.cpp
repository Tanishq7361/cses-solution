#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define vll vector<ll>

void solve(){
    ll n;
    cin>>n;
    vll a(n);
    ll tot=0;
    ll mx=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        tot+=a[i];
        mx=max(mx,a[i]);
    }
    if((tot&1) || mx>tot/2){
        cout<<"IMPOSSIBLE"<<endl;
        return ;
    }
    priority_queue<pair<ll,ll>>pq;
    for(int i=0;i<n;i++){
        if(a[i]>0){
            pq.push({a[i],i+1});
        }
    }
    vector<pair<ll,ll>>ans;
    while(!pq.empty()){
        if(pq.size()<=1){
            break;
        }
        pair<ll,ll>w1=pq.top();
        pq.pop();
        pair<ll,ll>w2=pq.top();
        pq.pop();
        w1.first--;
        w2.first--;
        ans.push_back({w1.second,w2.second});
        if(w1.first!=0){
            pq.push(w1);
        }
        if(w2.first!=0){
            pq.push(w2);
        }
    }
    cout<<ans.size()<<endl;
    for(auto &x:ans){
        cout<<x.first<<' '<<x.second<<endl;
    }
}

int main(){
    fastio;
    int tt=1;
    // cin>>tt;
    for(int i=1;i<=tt;i++){
        solve();
    }
    return 0;
}