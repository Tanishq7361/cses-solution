///////////////////////////////////////////////////////////////////////////////////////////

// Date : 14-07-2025
// problem : Sliding Window Minimum

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

struct AggStack {
    stack<pair<int, int>> st;
    void push(int x) {
        int cur = st.empty() ? x : min(st.top().second, x);
        st.push({x, cur});
    }
    void pop() {
        st.pop();
    }
    int agg() const {
        return st.top().second;
    }
};
struct AggQueue {
    AggStack in, out;

    void push(int x) {
        in.push(x);
    }
    void pop() {
        if (out.st.empty()) {
            while (!in.st.empty()) {
                int v = in.st.top().first;
                in.pop();
                out.push(v);
            }
        }
        out.pop();
    }
    int query() const {
        if (in.st.empty()) return out.agg();
        if (out.st.empty()) return in.agg();
        return min(in.agg(), out.agg());
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,k;
    cin>>n>>k;
    ll x,a,b,c;
    cin>>x>>a>>b>>c;
    AggQueue mq;
    ll final=x;
    ll ans=0;
    for(int i=0;i<k;i++){
        mq.push(final);
        final=(a*final +b)%c;
    }
    ans^=mq.query();
    for(int i=k;i<n;i++){
        mq.push(final);
        mq.pop();
        ans^=mq.query();
        final=(a*final +b)%c;
    }
    cout<<ans<<endl;
}