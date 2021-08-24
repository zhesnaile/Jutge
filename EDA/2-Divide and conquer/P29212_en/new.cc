#include<iostream>
using namespace std;

/*  2 <= n <= 30000
 *  2 <= m <= 30000
 *  n^k mod m
*/
int modular_exponentiation(int n, int k, int m){
    if(k == 1) return n%m;
    int a = modular_exponentiation(n, k/2, m);
    if(k%2==0) return (a*a)%m;
    else return( (a*n)%m * a)%m;
}

int main(){
    int n, k, m;
    while(cin>>n>>k>>m)
        cout << modular_exponentiation(n,k,m) << endl;
}
