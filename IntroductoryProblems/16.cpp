///////////////////////////////////////////////////////////////////////////////////////////
// Date : 22-11-2024
// problem : Apple division

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>
int main()
{
    long long int n;
    cin >> n;
    long long int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long int sum1 = 0, sum2 = 0;
    sort(a, a + n);
    ll ans;
    for (int i = n-1; i >=0; i--)
    {
        if (sum1 < sum2)
        {
            sum1 += a[i];
        }
        else
        {
            sum2 += a[i];
        }
    }
    ans = abs(sum1 - sum2);
    cout << ans << endl;
}