#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(2);
    double n, s, ss, b;
    s=0;
    ss=0;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> b;
        s=s+pow(b,2);
        ss=ss+b;
    }
    cout << ((1/(n-1)*s)-((1/(n*(n-1)))*pow(ss,2))) << endl;
}