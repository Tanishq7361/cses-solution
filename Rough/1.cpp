#include <bits/stdc++.h>
using namespace std;

void dfs(int x, int y, int ct, string &s, vector<vector<bool>> &vis, int &ans) {
    // If we reach (6,0) before 48 steps — valid only if ct == 48
    if (x == 6 && y == 0) {
        if (ct == 48) ans++;
        return;
    }

    // If we hit 48 steps without reaching (6,0), it's invalid
    if (ct == 48) return;

    // Dead-end pruning: trap detection
    if ((x == 0 || vis[x - 1][y]) && (x == 6 || vis[x + 1][y]) &&
        (y > 0 && !vis[x][y - 1]) && (y < 6 && !vis[x][y + 1])) return;
    if ((y == 0 || vis[x][y - 1]) && (y == 6 || vis[x][y + 1]) &&
        (x > 0 && !vis[x - 1][y]) && (x < 6 && !vis[x + 1][y])) return;

    vis[x][y] = true;

    const vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    const string d = "DURL";

    for (int i = 0; i < 4; i++) {
        int nx = x + dir[i].first;
        int ny = y + dir[i].second;

        if (s[ct] == '?' || s[ct] == d[i]) {
            if (nx >= 0 && ny >= 0 && nx < 7 && ny < 7 && !vis[nx][ny]) {
                dfs(nx, ny, ct + 1, s, vis, ans);
            }
        }
    }

    vis[x][y] = false;
}

int main() {
    string s;
    cin >> s;

    vector<vector<bool>> vis(7, vector<bool>(7, false));
    int ans = 0;

    dfs(0, 0, 0, s, vis, ans);
    cout << ans << endl;

    return 0;
}
