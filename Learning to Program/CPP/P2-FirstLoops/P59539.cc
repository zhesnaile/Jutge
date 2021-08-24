#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n;
    double c=0.0;
    cin >> n;
    for(int p=1; p<n+1; p++){
        c = c + double(1)/double(p);
    }
    cout << fixed;
    cout << setprecision(4);
    cout << c << endl;
}