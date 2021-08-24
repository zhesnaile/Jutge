#include <iostream>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
    double c, i, t;
    string kind;
    cin >>  c >> i >> t >> kind;
    if (kind=="simple") cout << (c*(1+i*t/100)) << endl;
    else {
        double k=1;
        for(int n=0; n<t; n++) k=k*(1+i/100);
        cout << c*k << endl;
    }
}