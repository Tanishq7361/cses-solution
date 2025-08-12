#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int &x : a) cin >> x;

        // Fill -1 with placeholder (just skip them for now)
        vector<int> filtered;

        for (int i = 0; i < n; ++i) {
            if (a[i] != -1) {
                filtered.push_back(a[i]);
            }
        }

        // Now check consecutive values in filtered array
        bool ok = true;
        for (int i = 1; i < filtered.size(); ++i) {
            if (abs(filtered[i] - filtered[i - 1]) > 2) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
