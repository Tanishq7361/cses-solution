///////////////////////////////////////////////////////////////////////////////////////////

// Date : 17-03-2025
// problem : Maximum Subarray Sum

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>
int main()
{
    ll n;
    cin >> n;
    vll a(n);
    ll temp=-1*(1e9);
    for(int i=0;i<n;i++){
        cin>>a[i];
        temp=max(temp,a[i]);
    }
    ll sum = 0;
    ll mx = 0;
    ll l = 0, r = 0;
    while (r < n)
    {
        if (sum < 0)
        {
            sum -= a[l];
            l++;
        }
        else
        {
            sum += a[r];
            if (sum > mx)
            {
                mx = sum;
            }
            r++;
        }
    }
    if(temp<=0){
        cout<<temp<<endl;
    }
    else{
    cout<<mx<<endl;
    }
}