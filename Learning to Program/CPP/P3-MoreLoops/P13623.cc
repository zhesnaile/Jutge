#include <iostream>
using namespace std;

int main(){
    int r, c, s=0;
    cin >> r >> c;
    char n;
    for (int a=0; a<r; a++){
        for (int b=0; b<c; b++){
            cin >> n;
            if (a%2==b%2) s+=(n-'0');
        }
    }
    cout << s << endl;
}