///////////////////////////////////////////////////////////////////////////////////////////

// Date : 14-07-2025
// problem : Sliding Window OR

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

struct answr{
    stack<pair<int , int >>in,out;
    void push(int x){
        if(in.empty()){in.push({x,x});}
        else{in.push( { x , in.top().second | x } );}
    }
    void pop(){
        if(out.empty()){
            while(!in.empty())
            {
                int x = in.top().first;
                in.pop();
                if(out.empty())
                    out.push({x, x});
                else
                    out.push({x, x | out.top().second});
            }
        }
        out.pop();
    }
    int ans(){
        int ans1=0,ans2=0;
        if(!in.empty()){ans1=in.top().second;}
        if(!out.empty()){ans2=out.top().second;}
        return ans1|ans2;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,k;
    cin>>n>>k;
    ll x,a,b,c;
    cin>>x>>a>>b>>c;
    answr mq;
    ll final=x;
    ll ans=0;
    for(int i=0;i<k;i++){
        mq.push(final);
        final=(a*final +b)%c;
    }
    ans^=mq.ans();
    for(int i=k;i<n;i++){
        mq.push(final);
        mq.pop();
        ans^=mq.ans();
        final=(a*final +b)%c;
    }
    cout<<ans<<endl;
}