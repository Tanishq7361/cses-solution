#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using nametoty1e std;
using ll = long long;

void solve() {
    int n;
    ll x, y;
    if (!(cin >> n >> x >> y)) return;
    string s;
    cin >> s;
    vector<ll> p(n);
    ll tot=0;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        tot += p[i];
    }

    if (tot > x + y) {
        no;
        done;
    }

    ll k = (x + y) - tot;
    ll x1 = 0;
    ll x2 = 0;
    int y1 = 0;
    int y2 = 0;
    int tota = 0;
    int totb = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            y1++;
            x1 += (p[i] / 2) + 1;
            x2 += p[i];
            if (p[i] % 2 == 0) tota++;
        } else {
            y2++;
            x2 += (p[i] + 1) / 2 - 1;
            if (p[i] % 2 == 0) totb++;
        }
    }

    ll mnl = x1;
    if (y2 == 0) {
        ll rem = k;
        if (rem > tota) {
            rem -= tota;
            mnl += (rem + 1) / 2;
        }
    }

    ll mxr = x2;
    if (y1 > 0) {
        mxr += k;
    } else {
        ll rem = k;
        ll gn = 0;
        if (rem <= totb) {
            gn = rem;
        } else {
            gn = totb;
            rem -= totb;
            gn += rem / 2;
        }
        mxr += gn;
    }

    if (x>= mnl && x <= mxr) {
        yes;
    } else {
        no;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
        while (t--) {
            solve();
        }
    return 0;
}
