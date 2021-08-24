#include <iostream>
using namespace std;
 
int main(){
        int n;
        cin >> n;
       
        while (n > 1){
                int r = n%2;
                n /= 2;
                cout << r;
        }
       
        if (n == 1 or n == 0) cout << n << endl;
}