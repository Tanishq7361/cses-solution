///////////////////////////////////////////////////////////////////////////////////////////
// Date : 08-06-2025
// problem : concert tickets

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<long long int>

int main()
{
    ll n, m;
    cin >> n >> m;
    vll t(m);
    set<ll> h;
    unordered_map<ll, ll> mpp;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        h.insert(x);
        mpp[x]++;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> t[i];
    }
    // lower bound in set very good concept
    for (int i = 0; i < m; i++)
    {
        auto it = h.upper_bound(t[i]);
        if (it == h.begin())
        {
            cout << -1 << endl;
        }
        else if (it != h.end())
        {
            it--;
            cout << *it << endl;
            mpp[*it]--;
            if (mpp[*it] == 0)
            {
                h.erase(it);
            }
        }
        else if (it == h.end())
        {
            it--;
            cout << *it << endl;
            mpp[*it]--;
            if (mpp[*it] == 0)
            {
                h.erase(it);
            }
        }
    }
    cout << endl;
}