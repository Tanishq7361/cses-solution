///////////////////////////////////////////////////////////////////////////////////////////

// Date : 28-07-2025
// problem : Point Location Test

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define vll vector<long long>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        double x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        double slope=(double)(y2-y1)/(double)(x2-x1);
        if(y3-y1==slope*(x3-x1)){
            cout<<"TOUCH"<<endl;
        }
        else if(y3-y1 - slope*(x3-x1) < 0){
            cout<<"LEFT"<<endl;
        }
        else{
            cout<<"RIGHT"<<endl;
        }
    }

}