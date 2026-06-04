#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 998244353;
static const int MAXN = 200000 + 5;

long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

long long fact[MAXN], invfact[MAXN];

long long C(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) fact[i] = fact[i - 1] * i % MOD;

    invfact[MAXN - 1] = modpow(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--)
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        long long ans = 0;

        for (int r = 0; r <= K; r++) {
            long long ways = C(N - r - 1, K - r);
            long long pw = (r == 0 ? (K == 0) : modpow(r, K));
            ans = (ans + pw * ways) % MOD;
        }

        cout << ans % MOD << '\n';
    }

    return 0;
}