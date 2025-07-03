///////////////////////////////////////////////////////////////////////////////////////////

// Date : 08-04-2025
// problem : Towers

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<long long int>
int main()
{
    ll n;
    cin>>n;
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vll tower;
    for(int i=0;i<n;i++){

        if(tower.size()==0 || tower.back()<=a[i]){
            tower.push_back(a[i]);
        }
        else{
            ll z=upper_bound(tower.begin(),tower.end(),a[i])-tower.begin();
            tower[z]=a[i];
        }
    }
    cout<<tower.size()<<endl;
}