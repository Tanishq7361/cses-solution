#include<iostream>
#include<vector>
using namespace std;

void solve(){
		int n,m,c;
		cin>>n>>m>>c;
		
		vector<int> a(n);
		vector<int> b(m);
		vector<int>pref(m+1,0);
		
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i =0;i<m;i++){
			cin>>b[i];
		}
		for(int i =0;i<m;i++){
			pref[i+1]=pref[i]+b[i];
		}
		if(m>n-m+1){
            for(int i=0;i<n-m;i++){
                a[i]+=pref[i+1];
                //a[i]%=c;
            }
			for(int i=n-m+1;i<m;i++){
				a[i]+=pref[i+1]-pref[i-m+2];
				//a[i]%=c;
			}
			for(int i=m;i<n;i++){
			    a[i]+=pref[m]-pref[i];
			    //a[i]%=c;
			}
		}
		else{
            for(int i=0;i<m;i++){
                a[i]+=pref[i];
            }
		    for(int i=m;i<n;i++){
                a[i]+=pref[m]-pref[i]; 
		        //a[i]%=c;
		    }
		}
		for(int i=0;i<n;i++){
		    cout<<a[i]<<' ';
		}
		cout<<endl;
}

int main(){
	int t =1;
//	cin>>t;
	while(t--){
	solve();
	}	
}