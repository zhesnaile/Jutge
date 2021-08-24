#include<iostream>
using namespace std;

int expo(int n, int k, int m){
    if (k==0) return 1;
    else {
        int a = expo(n, k/2, m);
        if (k%2==0) return (a*a) % m;
        else return ((a*n)%m * a)%m;
    }
}

int main(){
    int x, y, z;
    while (cin>>x>>y>>z) cout << expo(x, y, z);
}
