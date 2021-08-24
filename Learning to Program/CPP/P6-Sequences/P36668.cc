#include <iostream>
using namespace std;

int main(){
    int a, s=0;
    cin>>a;
    for(int b=1; b<=a; b++) s+=b*b;
    cout << s << endl; 
}