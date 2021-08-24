#include <iostream>
using namespace std;

int smolpro(int x, int y){
    int d=x/y;
    if (x%y!=0) y*=(d+1);
    else y*=d;
    return(y);
}
int main() {
    int a, b, c=1;
    while (cin>>a>>b){
        cout << '#' << c << " : " << smolpro(a,b) << endl;
        ++c;
    }
}