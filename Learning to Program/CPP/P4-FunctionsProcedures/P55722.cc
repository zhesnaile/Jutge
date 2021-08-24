#include <iostream>
using namespace std;

int number_of_digits(int n){
    int a=0;
    if (n==0) a=1;
    while (n>0){
        ++a;
        n/=10;
    }
    return a;
}

int main(){
    int x;
    cin>>x;
    cout << number_of_digits(x) << endl;
}