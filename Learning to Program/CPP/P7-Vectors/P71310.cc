#include <iostream>
#include <vector>
using namespace std;

double scalar_product(const vector<double>& u, const vector<double>& v){
    int l=u.size();
    double k=0;
    for (int o=0; o<l; ++o) k=k+(u[o]*v[o]);
    return k;
}
int main(){
    int n;
    vector<double> a(n);
    vector<double> b(n);
    for (int i=0; i<=n; ++i){
        cin>>a[i];
        cin>>b[i];
    }
    cout << scalar_product(a, b) << endl;
}