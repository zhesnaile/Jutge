#include <iostream>
using namespace std;

int main(){
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if (x<=b){
        if (x<=a){
            if (y<=b){
                cout << '[' << a << ',' << y << ']' << endl;
            }
            else {
                cout << '[' << a << ',' << b << ']' << endl;
            }
        }
        else {
            if (y<=b){
                cout << '[' << x << ',' << y << ']' << endl;
            }
            else {
                cout << '[' << x << ',' << b << ']' << endl;
            }
        }
    }
    else {
        cout << "[]" << endl;
    }
}