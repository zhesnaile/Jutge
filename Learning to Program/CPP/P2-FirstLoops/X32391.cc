#include <iostream>
using namespace std;

int main() {
    int d, n, t, a, c;
    c=0;
    cin >> d >> n >> t;
    for (int i=0; i<t; i++){
        cin >> a;
        n=n-d+a;
        if (n>0) ++c;
    }
    cout << c << endl;
}