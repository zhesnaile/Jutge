#include <iostream>
using namespace std;

int main() {
    int h, m, s;
    cin >> h >> m >> s;
    if (s==59){
        s=0;
        if (m==59){
            m=0;
            if (h==23){
                h=0;
                
            }
            else {
                h++;
            }
        }
        else {
            m++;
        }
    }
    else{
        s++;
    }
    if (h<10){
        cout << '0';
    }
    cout << h << ':';
    if (m<10){
        cout << '0';
    }
    cout << m << ':';
    if (s<10){
        cout << '0';
    }
    cout << s << endl;
}