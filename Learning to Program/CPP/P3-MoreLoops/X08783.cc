#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int b, n;
    while (cin >> b >> n){
        int c=0;
        while (pow(b,c)<=n) c++;
        cout << c << endl;
    }
}