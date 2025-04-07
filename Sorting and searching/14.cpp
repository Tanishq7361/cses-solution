///////////////////////////////////////////////////////////////////////////////////////////

// Date : 08-04-2025
// problem : Playlist

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>
int main()
{
    ll n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<ll, ll> mpp;
    ll st = 0;
    ll rr = 0;
    ll ans = 1;
    while (rr < n)
    {
        if (mpp[a[rr]] == 1)
        {
            mpp[a[st]]--;
            st++;
        }
        else
        {
            mpp[a[rr]]++;
            rr++;
        }
        // cout<<rr<<endl;
        ans = max(ans, rr - st);
    }
    cout << ans << endl;
}