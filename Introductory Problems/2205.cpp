///////////////////////////////////////////////////////////////////////////////////////////

// Date : 09-01-2025
// problem : Gray code

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define vll vector<long long int>
int main()
{
    ll n;
    cin>>n;
    vector<string>ans;
    vector<string>temp;
    ans.pb("0");
    ans.pb("1");
    n=n-1;
    while(n>0){
        for(int i=0;i<ans.size();i++){
            temp.pb("0"+ans[i]);
        }
        for(int i=ans.size()-1;i>=0;i--){
            temp.pb("1"+ans[i]);
        }
        ans.clear();
        ans.assign(temp.begin(),temp.end());
        temp.clear();
        n--;
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}