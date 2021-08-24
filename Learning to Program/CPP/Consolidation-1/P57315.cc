#include <iostream>
using namespace std;

int main() {
    int x,y,z,a;
    string j;
    cin >> x >> y >> z >> j;
    if (x<y and y<z) {
        a=x;
        x=y;
        y=z;
    }
    else if (x>y and x<z){
        a=y;
        y=z;
    } 
    else if (x>z and z>y){
        a=y;
        y=x;
        x=z;
    }
    else if (x<z and z<y){
        a=x;
        x=z;
    }
    else if (z<y and y<x){
        a=z;
        z=x;
        x=y;
        y=z;
    }
    else a=z;
    cin >> j;
    if (j=="ABC") cout << a << " " << x << " " << y << endl;
    if (j=="ACB") cout << a << " " << y << " " << x << endl;
    if (j=="BAC") cout << x << " " << a << " " << y << endl;
    if (j=="BCA") cout << x << " " << y << " " << a << endl;
    if (j=="CAB") cout << y << " " << a << " " << x << endl;
    if (j=="CBA") cout << y << " " << x << " " << a << endl;
}