#include <iostream>
using namespace std;

int main() {
    char c;
    bool a = false, end = false;
    while (a != 1 and end != 1 and cin >> c){
        if (c == 'a') a = true;
        else if (c == '.') end = true;
    }
    if (a == 1) cout << "yes" << endl;
    else cout << "no" << endl; 
}