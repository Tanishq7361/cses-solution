///////////////////////////////////////////////////////////////////////////////////////////

// Date : 05-07-2025
// problem : String Reorder

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    cin>>s;
    ll n=s.size();
    vector<ll>hash(26);
    ll mxx=0;
    for(int i=0;i<n;i++){
        hash[s[i]-'A']++;
        mxx=max(mxx,hash[s[i]-'A']);
    }
    if(2*mxx>n+1){
        cout<<-1<<endl;
        return 0;
    }
    vll ans(n);
    ll prev=81;
    for(int i=0;i<n;i++){
        ll rem=n-i;
        ll mx=0;
        ll inx=-1;
        ll low=-1;
        for(int j=0;j<26;j++){
            if(low==-1 && hash[j]>0 && prev!=j) low=j;
            if(hash[j]>mx){
                mx=hash[j];
                inx=j;
            }
        }
        if(2*mx==rem+1) ans[i]=inx;
        else ans[i]=low;

        hash[ans[i]]--;
        prev=ans[i];
    }
    for(int i=0;i<n;i++){
        cout<<(char)(ans[i]+'A');
    }

}