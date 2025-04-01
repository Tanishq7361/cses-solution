///////////////////////////////////////////////////////////////////////////////////////////
// Date : 24-11-2024
// problem : tower of hanoi

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>

void hanoi(char f, char u, char t, ll n)
{
    if(n==0){
       return;
    }
    hanoi(f, t, u, n - 1);
    cout << f << " " << t << endl;
    hanoi(u, f, t, n - 1);
    return;
}

int main()
{
    ll n;
    cin >> n;
    cout<< pow(2,n) - 1<<endl;
    hanoi('1', '2', '3', n);
}