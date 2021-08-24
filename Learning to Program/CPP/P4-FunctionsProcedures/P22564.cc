#include <iostream>
using namespace std;

void decompose(int n, int& h, int& m, int& s){
    h=n/3600;
    m=(n%3600)/60;
    s=(n%(3600/60));
}

int main(){
    int a, h=0, m=0, s=0;
    cin>>a;
    decompose(a,h,m,s);
}