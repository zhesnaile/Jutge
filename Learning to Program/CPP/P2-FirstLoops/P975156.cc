#include <iostream>
using namespace std;

int main() {
    int a, b;
    int i;
    cin >> a >> b;
    if (a<b){
        for (i=a, i<b, i++){
          cout << i << ",";
        }
        cout << b << endl;  
        
    }
    else {
        for (i=b, i<a, i++){
          cout << i << ",";
        }
        cout << a << endl;}
}