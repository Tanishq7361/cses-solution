///////////////////////////////////////////////////////////////////////////////////////////

// Date : 26-08-2025
// problem : Josephus Problem 2

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,k=1;
    cin>>n>>k;

    // this is general approach for any k 

    ordered_set<int> s;
    for (int i = 1; i <= n; i++){
        s.insert(i);
    }
    ll idx = 0;
    while (!s.empty()) {
        idx = (idx + k) % s.size();
        auto it = s.find_by_order(idx);
        cout << *it << " ";
        s.erase(it);
    }
}