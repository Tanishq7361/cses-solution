///////////////////////////////////////////////////////////////////////////////////////////
// Date : 22-11-2024
// problem : Digit Queries

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>
int main()
{
    ll q;
    cin >> q;

    while (q--)
    {

        ll k;
        cin >> k;
        ll sum = 0;
        ll one = 9;
        ll i = 1;
        while (k > 0)
        {

            if (k - one * i > 0)
            {
                k -= one * i;
                sum += one;
                one *= 10;
                i++;
            }
            else
            {
                break;
            }
            // cout << k << endl;
        }
        // cout << sum << endl;
        sum += k / i;
        // cout << k << endl;
        //cout << sum << endl;
        //cout << k << endl;
        if (k % i == 0)
        {
            cout << sum % 10 << endl;
        }

        else
        {
            ll r = k % i;
            sum++;
            ll ans = sum % 10;

            while (i - r)
            {
                sum = sum / 10;
                i--;
            }
            ans = sum % 10;
            cout << ans << endl;
        }
        // cout << sum << endl;
    }
}