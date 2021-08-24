#include <iostream>
using namespace std;

int main() {
    int n, s;
    int c=0;
    cin >> n;
    cout << "nombres que acaben igual que " << n << ':' << endl;
    while(cin >> s){
        if (n%1000==s%1000){
            cout << s << endl;
            c++;
        }
    }
    cout << "total: " << c << endl;
}