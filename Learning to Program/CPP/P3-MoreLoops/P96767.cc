#include<iostream>
using namespace std;
 
 
int main() {
        cout.setf(ios::fixed);
        cout.precision(4);
        double z;
        cin >> z;
        int count = 0;
        double aux = 1;
        double s = 0;
        double m;
        while (cin >> m) {
                if (count == 0) {
                        s+=m;
                        ++count;
                }
                else  {
                        aux*=z;
                        s+=m*aux;
                }
        }
        cout << s << endl;
}