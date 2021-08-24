#include <iostream>
using namespace std;

int factorial(int n){
    int a=1;
    for (int b=n; b>0; --b) a*=b;
    return a;
}

int main(){
    int x;
    cin>>x;
    cout<<factorial(x)<<endl;
}