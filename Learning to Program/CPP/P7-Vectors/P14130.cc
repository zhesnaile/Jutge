#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, s=0;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i<n; ++i) cin >> v[i];
    for (int a=0; a<(n-1); ++a){
        if (v[a]==v[n-1]) ++s;
    }
    cout << s << endl;
}