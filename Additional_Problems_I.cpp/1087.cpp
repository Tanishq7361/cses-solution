// Date : 23-12-2025

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MOD = 1e9 +7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    ll n=s.size();
    set<char>st;
    ll cnt=0;
    vector<char>a={'A','C','G','T'};
    for(int i=0;i<n;i++){
        st.insert(s[i]);
        if(st.size()==4){
            st.clear();
            cnt++;
        }
    }
    char c='A';
    for(int i=0;i<4;i++){
        if(st.find(a[i])==st.end()){
            c=a[i];
            break;
        }
    }
    for(int i=0;i<=cnt;i++){
        cout<<c;
    }
    cout<<endl;
}