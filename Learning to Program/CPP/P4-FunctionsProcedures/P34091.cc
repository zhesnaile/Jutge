#include <iostream>
using namespace std;

bool is_perfect(int n){
    int s=1;
    for (int a=2; a*a<=n; ++a){
        if (n%a==0) s+=a +n/a;
    }
    if (n!=0 and n!=1) return (s==n);
    else return false;
}
int main(){
    int x;
    cin >> x;
    cout << is_perfect(x) << endl;
}