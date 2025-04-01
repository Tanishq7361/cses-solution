///////////////////////////////////////////////////////////////////////////////////////////
// Date : 23-11-2024
// problem : Ferris Wheel

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>
int main()
{
    ll n, x;
    cin >> n >> x;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    ll l = 0, r = n - 1;

    ll ct = 0;
    while (l < r)
    {
        ll sum=a[l]+a[r];
        if(sum<=x){
            ct++;
            l++;
        }
        r--;
    }
    cout << n - ct << endl;
}