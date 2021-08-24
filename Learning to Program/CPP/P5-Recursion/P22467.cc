#include <iostream>
#include <cmath>
using namespace std;
int sum_of_digits(int n){
    int s=0;
    while (n>0){
        s+=(n%10);
        n/=10;
    }
    return (s);
}
bool is_prime(int n){
    if (n<=1) return false;
    for (int a=2; a<sqrt(n); ++a) if (n%a==0) return false;
    return true;
}

bool is_perfect_prime(int n){
    if (n<10 and is_prime(n)) return true;
    else if ((is_prime(n)==1) and (is_perfect_prime(sum_of_digits(n))==true)) return true;
    else return false;
}
int main() {
    int k;
    cin >> k;
    cout << is_perfect_prime(k) << endl;
}