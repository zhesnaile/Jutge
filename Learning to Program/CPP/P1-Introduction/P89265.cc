#include <iostream>
using namespace std;

int main(){
    unsigned int a, b, x, y;
    cin >> a >> b >> x >> y;
    if (a==x and b==y){
        cout << "= , " << '[' << a << ',' << b << ']' << endl;
    }
    else if  (a<x and b>y){
        cout << "2 , " << '[' << x << ',' << y << ']' << endl;
    }
    else if (a>x and b<y){
        cout << "1 , " << '[' << a << ',' << b << ']' << endl;
    }
    else{
        if ((b<x and a<y)or (b>x and a>y)){
            cout << "? , " << "[]" << endl;
        }
        else{
            if (a<=x and b>=x){
                cout << "? , " << '[' << x << ',' << b << ']' << endl; 
            }
            else {
                cout << "? , " << '[' << y << ',' << a << ']' << endl;
            }
        }
    }
}