#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int b, c, s=0;
    cin >> b;
    while (cin >> c){
        cout << c << ": ";
        while(c!=0){
        s+=(c%b);
        c/=b;
        }
        cout << s << endl;
        s=0;
    }
}