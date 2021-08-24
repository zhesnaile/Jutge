

#include <iostream>
using namespace std;
 
 
bool is_prime(int a) {
        if (a <= 1) return false;
        for (int i = 2; i*i <= a; ++i) {
                if (a%i == 0) return false;
        }
        return true;
}
 
bool is_perfect_prime(int n) {
        if (not is_prime(n)) return false;
        int r = 0;
        int d = 0;
        while (n > 0) {
                r = r + n%10;
                n = n/10;
                ++d;
        }
        bool r_is_prime = is_prime(r);
        if (r_is_prime && d == 1) return true;
        else if (r_is_prime) return is_perfect_prime(r);
        else return false;
}
int main() {
        int n;
        while (cin >> n) {
                cout << is_perfect_prime(n) << endl;
        }
}