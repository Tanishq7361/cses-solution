///////////////////////////////////////////////////////////////////////////////////////////
 
// Date : 12-11-2025
// problem : collecting Numbers 2
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define vll vector<long long int>

struct custom_hash { //to avoid TLE due to collision in unordered_map
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    template<typename L, typename R>
    size_t operator()(pair<L,R> const& Y) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31 + Y.second + FIXED_RANDOM);
    }
};

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n+1];
    unordered_map<ll,ll,custom_hash>mpp;
    // map<ll,ll>mpp;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mpp[a[i]]=i;
    }
    ll prev=-1;
    ll ans=1;
    for(int i=1;i<=n;i++){
        if(mpp[i]<prev){
            ans++;
        }
        prev=mpp[i];
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        if(a[x]-1 >=1 && mpp[a[x]-1] <= mpp[a[x]] && y < mpp[a[x]-1]) ans++;
        if(a[x]-1 >=1 && mpp[a[x]-1] > mpp[a[x]] && y >= mpp[a[x]-1]) ans--;
        if(a[x]+1 <=n && mpp[a[x]+1] >= mpp[a[x]] && y > mpp[a[x]+1]) ans++;
        if(a[x]+1 <=n && mpp[a[x]+1] < mpp[a[x]] && y <= mpp[a[x]+1]) ans--;
        mpp[a[x]] = y;
        if(a[y]-1 >=1 && mpp[a[y]-1] <= mpp[a[y]] && x < mpp[a[y]-1]) ans++;
        if(a[y]-1 >=1 && mpp[a[y]-1] > mpp[a[y]] && x >= mpp[a[y]-1]) ans--;
        if(a[y]+1 >=1 && mpp[a[y]+1] >= mpp[a[y]] && x > mpp[a[y]+1]) ans++;
        if(a[y]+1 >=1 && mpp[a[y]+1] < mpp[a[y]] && x <= mpp[a[y]+1]) ans--;
        mpp[a[y]] = x;
        swap(a[x], a[y]);
        cout<<ans<<endl;
    }
    return 0;
}