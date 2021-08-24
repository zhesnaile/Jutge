#include <iostream>
using namespace std;

int main() {
    int a, r;
    cin >> a;
    r = (a%10)+ (a/10)%10 + (a/100)%10;
    cout << r << endl;
}