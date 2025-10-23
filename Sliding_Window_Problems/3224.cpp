///////////////////////////////////////////////////////////////////////////////////////////

// Date : 23-10-2025
// problem : Sliding Window Mode

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]*=-1;
    }
    priority_queue<pair<ll,ll>>pq;
    map<ll,ll>mpp;
    for(int i=0;i<k;i++){
        mpp[a[i]]++;
        pq.push({mpp[a[i]],a[i]});
    }
    cout<<0-pq.top().second<<' ';
    for(int i=k;i<n;i++){
        mpp[a[i-k]]--;
        mpp[a[i]]++;
        pq.push({mpp[a[i]],a[i]});
        while(pq.top().first!=mpp[pq.top().second]){
            pq.pop();
        }
        cout<<0-pq.top().second<<' ';
    }
}