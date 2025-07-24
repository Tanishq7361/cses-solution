///////////////////////////////////////////////////////////////////////////////////////////

// Date : 14-07-2025
// problem : Sliding Window Mode

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

struct custom_hash {
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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    unordered_map<ll,ll,custom_hash>mpp;
    ll n,k;
    cin>>n>>k;
    stack<pair<ll,ll>>stk;
    for(int i=0;i<k;i++){
        ll x;
        cin>>x;
        mpp[x]++;
        if(stk.empty()){
            stk.push({mpp[x],x});
        }
        else{
            while(stk.top().first < mpp[x]){
                stk.pop();
            }
            if(stk.top().first==mpp[x]){
                if(x<stk.top()){
                    stk.
                }
            }
        }
    }
}