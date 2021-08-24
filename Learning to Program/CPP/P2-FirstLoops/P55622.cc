#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    int i=0;
    cin >> n;
    if (n==0){
        cout << "The number of digits of 0 is 1." << endl;
    }
    else{
        while (pow (10,i)<=n){
            i++;
        }
        cout << "The number of digits of " << n << " is " << i << '.' << endl;
    }
}