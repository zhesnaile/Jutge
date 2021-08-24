#include <iostream>
using namespace std;

int main() {
    int a, b;
    int i;
    cin >> a >> b;
    if (a<=b){
        cout << a;
        ++a;
        while (a <= b){
            cout << ',' << a;
            ++a;
        }
    }
    cout << endl;
}