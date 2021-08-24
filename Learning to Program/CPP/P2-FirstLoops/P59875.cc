#include <iostream>
using namespace std;

int main() {
    int x, y, a;
    cin >> x >> y;
    if (x<y){
        a=y;
        y=x;
        x=a;
    }
    for (; x>=y; --x){
            cout << x << endl;
    }
}