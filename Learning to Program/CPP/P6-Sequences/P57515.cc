#include <iostream>
using namespace std;

int rotacio_dreta(int a, int b) {
    int m = 1;
    for (int c = a; c > 9; c /= 10) m *= 10;
    for (int i = 0; i < b; ++i) a = a/10 + m*(a%10);
    return a;
}

int main(){
    int x, k;
    while (cin>>x>>k) cout << rotacio_dreta(x,k) << endl;
}