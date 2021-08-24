#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if ((a<=b and a<=c) or (a>=b and a>=c) ){
        if ((b<=a and b<=c) or (b>=a and b>=c)) {
            cout << a+b << endl;
        }
        else{
            cout << a+c << endl;
        }
    }
    else {
        cout << c+b << endl;
    }
}