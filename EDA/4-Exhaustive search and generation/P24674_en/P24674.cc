#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
using namespace std;

int n;
vector<string> v;
vector <bool> usado;

void juantuene(int current){
  if (current == n){
    for (int i = 0; i < n; ++i){
      if (i == 0)cout << '(';
      cout << v[i];
      if ( i != n-1 ) cout << ',';
      else cout << ')' << endl;
    }
  }
  else{
    for (int i = 0; i < n; ++i){
      if ( !usado[i] ){
        usado[i]=true;
        v[current]=i+1;
        juantuene(current+1);
        usado[i]=false;
      }
    } 
  } 
}

int main(){
  cin>>n;
  v = vector<string> (n);
  for (int i = 0; i < n; ++i)
    cin >> v[i];
  usado = vector<bool> (n, 0);
  juantuene(0);
}

