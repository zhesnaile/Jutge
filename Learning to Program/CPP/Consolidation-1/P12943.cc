#include <iostream>
using namespace std;

int main(){
    int n, a=0, b=0, c=0;
    char k;
    cin >> n;
    for (int i=1; i<n; i++){
        cin >> k;
        if (k=='a') a++;
        else if (k=='b') b++;
        else if (k=='c') c++;
    }
    cout << "majoria de ";
    if ((a>b and a>c) or ((a==b and c<=a) or (a==c and b<=a))){
        cout << "a" << endl;
        cout << a << " repeticio(ns)" << endl;
    }
    else if ((b>a and b>c) or (b==c)){
        cout << "b" << endl;
        cout << b << " repeticio(ns)" << endl;
    }
    else if ((c>a and c>b) and (b!=c)){
        cout << "c" << endl;
        cout << c << " repeticio(ns)" << endl;
    }
}