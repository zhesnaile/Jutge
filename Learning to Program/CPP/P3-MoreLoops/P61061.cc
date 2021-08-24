#include <iostream>
using namespace std;
 
int main() {
 
    int a;
    int p=1;
    while (cin >> a){
        if (a==0)
            cout << "The product of the digits of " << a << " is " << a << "." << endl;
 
        else {
            while (a>0){
                cout << "The product of the digits of " << a << " is ";
                while(a>0){
                    p=p*(a%10);
                    a/=10;
                }
                cout << p << "." << endl;
                if (p>9)
                    a=p;
                p=1;
            }
        }
        cout << "----------" << endl;
    }
 
    return 0;
}