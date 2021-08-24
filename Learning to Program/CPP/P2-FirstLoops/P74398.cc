#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int k;
    int x=2;
    int y=0;
    cin >> k;
    for (x=2; x<=16; x++){
        while (pow(x,y)<=k){
            y++;
        }
        cout << "Base " << x << ": " << y << " cifras." << endl;
        y=0;
    }
}