#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, j;
    while (cin>>n){
        vector<int> v(n);
        for (int i=0; i<n; ++i) cin>>v[i];
        for (int a=0; a<(n/2); ++a){
            j=v[n-(1+a)];
            v[n-(a+1)]= v[a];
            v[a]=j;
        }
        for (int b=0; b<n; ++b){
            cout << v[b];
            if (b<(n-1)) cout<<" ";
        }
        cout<<endl;
    }
}