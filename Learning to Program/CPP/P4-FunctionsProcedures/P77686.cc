#include <iostream>
using namespace std;

int swap(int a){
    int b = 0;
    while(a > 0){
        b = b*10 + (a % 10);
        a = a/10;
    }
    return b;
}

bool is_palindromic(int n){
    if (n==swap(n)) return true;
    else return false;
}

int main(){
    int x;
    cin>>x;
    cout << is_palindromic(x) << endl;
}