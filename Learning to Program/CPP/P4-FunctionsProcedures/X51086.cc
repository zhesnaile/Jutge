#include <iostream>
using namespace std;

int dif(int x, int y){
    x-=y;
    return (x);
}

int main (){
    int a, b;
    cin >> a >> b;
    cout << dif(a,b) << endl;
}