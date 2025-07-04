///////////////////////////////////////////////////////////////////////////////////////////

// Date : 03-07-2025
// problem : Chessboard and queens

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

void rec(int col,vector<bool>&row,vector<bool>&diagup,vector<bool>&diagdown,vector<vector<char>>&board,ll&ans){
    if(col==8){
        ans++;
        return;
    }
    for(int i=0;i<8;i++){
        if(board[i][col]=='.' && !row[i] && !diagup[i+col] && !diagdown[i+7-col]){
            row[i]=true;
            diagup[i+col]=true;
            diagdown[i+7-col]=true;
            rec(col+1,row,diagup,diagdown,board,ans);
            row[i]=false;
            diagup[i+col]=false;
            diagdown[i+7-col]=false;
        }
    }
}

int main()
{
    ll ans=0;
    vector<vector<char>>board(8,vector<char>(8));
    vector<bool>row(8,false),diagup(15,false),diagdown(15,false);
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>board[i][j];
        }
    }
    rec(0,row,diagup,diagdown,board,ans);
    cout<<ans<<endl;
}