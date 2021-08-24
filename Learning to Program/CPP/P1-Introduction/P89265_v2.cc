#include <iostream>
using namespace std;
 
int main () {
    int a, b, c, d, x, y;
 
    cin >> a >> b >> c >> d;
    if (a<=c) {
        if (b<=d) {
            x=c;
            y=b;
        }
        else {
            x=c;
            y=d;
        }
    }
    else {
        if (b<=d) {
            x=a;
            y=b;
        }
        else {
            x=a;
            y=d;
        }
    }
   
    if (a==c && b==d) {
        cout << "= , ";
    }
    else if (a>=c && b<=d) {
        cout << "1 , ";
    }
    else if (a<=c && b>=d)  {
        cout << "2 , ";
    }
    else {
        cout << "? , ";
    }
   
    if (x<=y) {
        cout << "[" << x << "," << y << "]" << endl;
    }
    else {
        cout << "[]" << endl;
    }
}