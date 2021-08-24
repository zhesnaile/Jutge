#include <iostream>
#include <string>
using namespace std;

int main (){
    string a;
    int x=0;
    int y=0;
    cin >> a;
    for (int i=0; i<(a.length()); i++){
        if (a[i]=='n') --y;
        else if (a[i]=='s') y++;
        else if (a[i]=='e') x++;
        else --x;
    }
    cout << '(' << x << ", " << y << ')' << endl;
}