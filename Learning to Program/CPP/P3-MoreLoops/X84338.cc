#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, i=0, s1=0, s2=0, a ,b;
    cin >> n;
    while (n> pow(10,i)) i++;
    if (i%2!=0) cout << "nothing" << endl;
    else{
        a=n/pow(10,i/2);
        b=n%(pow(10,i/2));
        while (a!=0){
            s1+=(a%10);
            a/=10;
        }
        while (b!=0){
            s2+=(b%10);
            b/=10;
        }
        cout << s1;
        if (s1==s2) cout << " = ";
        else if (s1<s2) cout << " < ";
        else cout << " > ";
        cout << s2 << endl;
    }
}