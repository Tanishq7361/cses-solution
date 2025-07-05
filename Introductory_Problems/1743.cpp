///////////////////////////////////////////////////////////////////////////////////////////

// Date : 05-07-2025
// problem : String Reorder
// Not solved
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    cin>>s;
    ll n=s.size();
    unordered_map<char,ll>mpp;
    for(int i=0;i<n;i++){
        mpp[s[i]]++;
        if(mpp[s[i]] > ((n+1)/2)){
            cout<<"-1"<<endl;
            return 0;
        }
    }
    string ans(n,'.');
    ll inx=0;
    ll st=0;
    for(char c='A';c<='Z';c++){
        inx=st;
        while(mpp[c]>0){
            ans[inx]=c;
            mpp[c]--;
            inx+=2;
        }
        for(int i=st;i<n;i++){
            if(ans[i]=='.'){
                st=i;
                break;
            }
        }
    }
    cout<<ans<<endl;     
}