#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    if (a%4==0){
        if (a%100==0 and a%400==0){
            cout << "YES" << endl;
        }
        else if (a%100!=0){
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    else{
        cout << "NO" << endl;
    }
}