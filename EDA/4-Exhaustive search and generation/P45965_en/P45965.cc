#include<iostream>
#include<vector>
using namespace std;



void zerouno_ini(vector<bool> v, int n, int o, int no){
  if (o+no == 0){
    for (int i = 0; i < n; ++i){
      cout << v[i];
      if (i != n-1) cout << ' ';
    }
    cout << endl;
  }
  else{
    if ( no != 0 ){
      v[n] = false;
      zerouno_ini(v, n+1, o, no-1);
    }
    if ( o != 0 ){
      v[n] = true;
      zerouno_ini(v, n+1, o-1, no);
    }
  }
}

int main(){
    int n, o;
    cin >> n >> o;
    vector<bool> v(n);
    zerouno_ini(v, 0, o, n-o);
}
