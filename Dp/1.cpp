///////////////////////////////////////////////////////////////////////////////////////////

// Date : 09-04-2025
// problem : Dice Combination

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>
ll mod = 1e9 + 7;

int main()
{
    ll n;
    cin >> n;
    ll ans = 0;
    vll dp(n + 2, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int sum = 1; sum < n + 2; sum++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (sum >= j)
            {
                dp[sum] += dp[sum - j] % mod;
            }
        }
    }
    cout << dp[n + 1] % mod << endl;
}