#include <iostream>
using namespace std;
 
int main() {
    bool found = false;
    int i , x;
    cin >> i >> x;
    int k = 0;
    while (not found and x != -1) {
        ++k;
        if( k == i) found = true;
        else cin >> x;
    }
    if(found) cout << "At the position " << k << " there is a(n) " << x << "." << endl;
    else cout << "Incorrect position." << endl;
}