///////////////////////////////////////////////////////////////////////////////////////////

// Date : 27-06-2025
// problem : Hidden Integer

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

string ask(ll n) 
{
	cout << "? " <<n<< endl;
	cout.flush();
	string ans;
	cin >> ans;
	return ans;
}

void prin(ll n){ 
	cout << "! "<< n <<endl;
}

int main()
{
    ll low=1,high=1e9;
    ll N=30;
    while(low<high && N>0){
        ll mid=(low+high)/2;
        string ans=ask(mid);
        if(ans=="YES"){
            low=mid+1;
        }
        else{
            high=mid;
        }
        N--;
    }
    prin(high);
}