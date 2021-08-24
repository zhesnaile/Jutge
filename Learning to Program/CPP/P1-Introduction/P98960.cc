#include <iostream>
using namespace std;

int main() {
    char c;
    cin >> c;
    if (c>=65 and c<=90){
        c = c + 32;
        cout << c << endl;
    }
    else if (c>=97 and c<=122){
        c = c - 32;
        cout << c << endl;
    }
} 