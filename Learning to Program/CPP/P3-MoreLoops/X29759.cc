#include <iostream>
using namespace std;
 
int main () {
    int x, n = 0, m = 0, s;
    char t;
    cin >> x;
    for (int i = 0; i<x; i++){
        for (int j = 0; j<x; j++){
            cin >> t;
            if (((j+i)%2) == 0) {
                t = t - '0';
                s = int(t);
                n = n + s;
            }
            else {
                t = t - '0';
                s = int(t);
                m = m + s;
            }
        }
    }
    cout << n << '-' << m << " = ";
    if ((n-m)<0) cout << '-' << (m-n) << endl;
    else cout << (n-m) << endl;
}