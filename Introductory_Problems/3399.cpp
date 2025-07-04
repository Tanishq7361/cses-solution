///////////////////////////////////////////////////////////////////////////////////////////

// Date : 04-07-2025
// problem : Raab Game 1

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
int main()
{   
    int t;
    cin>>t;
    while(t--){
        ll n,a,b;
        cin>>n>>a>>b;
        if((a==0 && b!=0)  ||  (b==0 && a!=0)  ||  a+b>n){
            cout<<"NO"<<endl;
            continue;
        }
        vector<ll>ansa,ansb;
        ll z=n-a-b;
        ll ct=z+1,t1;
        for(int i=1;i<=z;i++){
            ansa.push_back(i);
            ansb.push_back(i);
        }
        if(a<b){
            t1=a-1;
            ll temp=ct;
            for(int i=temp;i< 2*t1 +temp;i+=2){
                ansa.push_back(i+1);
                ansb.push_back(i);
                ansa.push_back(i);
                ansb.push_back(i+1);
                ct+=2;
            }
            ansa.push_back(n);
            ansb.push_back(ct);
            ct++;
            for(int i=ct;i<=n;i++){
                ansb.push_back(i);
                ansa.push_back(i-1);
            }
        }
        else{
            t1=b-1;
            ll temp=ct;
            for(int i=temp;i< 2*t1 +temp;i+=2){
                ansb.push_back(i+1);
                ansa.push_back(i);
                ansb.push_back(i);
                ansa.push_back(i+1);
                ct+=2;
            }
            ansb.push_back(n);
            ansa.push_back(ct);
            ct++;
            for(int i=ct;i<=n;i++){
                ansa.push_back(i);
                ansb.push_back(i-1);
            }
        }
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++){
            cout<<ansa[i]<<' ';
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<ansb[i]<<' ';
        }
        cout<<endl;
    }
}