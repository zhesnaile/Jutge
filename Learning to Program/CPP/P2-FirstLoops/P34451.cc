#include <iostream>
using namespace std;

int main() {
    int a, b;
    int c=0;
    cin >> a;
    while(cin >> b){
        if (b%a==0) c++;
    }
    cout << c << endl;
}