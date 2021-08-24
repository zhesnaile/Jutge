#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    int a;
    cout<<std::fixed;
    while(cin>>a) cout << std::setprecision(0) << pow(a,2) << ' ' << std::setprecision(6) << sqrt(double (a)) << endl;
}