#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int a, b;
    while (cin >> a >> b){
        cout << "suma dels cubs entre " << a << " i " << b << ": ";
        int s = 0;
        while (a <= b) {
            s = s + pow (a,3);
            ++a;
        }
        cout << s << endl;
    }
}