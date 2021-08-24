#include <iostream>
using namespace std;

int main(){
    int a, b=0;
    bool x=false;
    while(cin>>a and x==false){
        if (a%2==0) x=true;
        ++b;
    }
    cout << b << endl;
}