/*  
    DATE    :   25-09-2024
    Problem :   Bit strings    
*/
#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

int main()
{
    int n;
    cin>>n;
    int i=1;
    while(n--){
        i*=2;
        i=i%M;
    }
    cout<<i;
    


}