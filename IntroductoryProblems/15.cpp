///////////////////////////////////////////////////////////////////////////////////////////
// Date : 27-11-2024
// problem : Creating strings

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>

ll fact(ll n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return fact(n - 1) * n;
}

int main()
{
    string s;
    cin >> s;
    ll n = s.size();
    ll hash[130] = {0};
    ll ans = fact(n);
    for (int i = 0; i < n; i++)
    {
        hash[s[i]]++;
    }
    for(int i=0;i<130;i++){
       ans=ans/fact(hash[i]);
    }
    cout<<ans<<endl;
    sort(s.begin(),s.end());
    do{
        cout<<s<<endl;
    }
    while(next_permutation(s.begin(),s.end()));
    
}