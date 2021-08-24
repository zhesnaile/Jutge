#include <iostream>
using namespace std;

void swap2(int& a, int& b){
    int z=a;
    a=b;
    b=z;
}

int main(){
    int a, b;
    cin>>a>>b;
    swap2(a,b);
    cout << a <<' '<< b << endl;
}