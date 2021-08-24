#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int>> Graph;

int main(){
  int t, n, m;
  cin >> t;
  for ( int i=0; i<t; ++t){
    cin>>n>>m;
    Graph board(n,vector<int>(m));
    for (int row=0; row<n; ++row){
      for (int column=0; column<n; ++column) cin>>board[row][column];
    }
    
  }
}
