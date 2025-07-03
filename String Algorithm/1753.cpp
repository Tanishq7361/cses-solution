///////////////////////////////////////////////////////////////////////////////////////////

// Date : 01-07-2025
// problem : string matching

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();
    int ans=0;
    for(int i=0;i<n;i++){
        string s=s1.substr(i,m);
        if(s2==s){
            ans++;
        }
    }
    cout<<ans<<endl;
}