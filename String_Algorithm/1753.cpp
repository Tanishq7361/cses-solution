///////////////////////////////////////////////////////////////////////////////////////////

// Date : 01-07-2025
// problem : string matching

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
void constructLps(string &s1, vector<int> &lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < s1.length()) {
        if (s1[i] == s1[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
ll search(string &s1, string &s2) {
    int n = s2.length();
    int m = s1.length();
    vector<int> lps(m);
    ll ct=0;
    constructLps(s1, lps);
    int i = 0;
    int j = 0;
    while (i < n) {
        if (s2[i] == s1[j]) {
            i++;
            j++;
            if (j == m) {
                ct++;
                j = lps[j - 1];
            }
        }
        else {
            if (j != 0){
                j = lps[j - 1];
            }
            else{
                i++;
            }
        }
    }
    return ct;
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    ll ans=search(s2,s1);
    cout<<ans<<endl;
}