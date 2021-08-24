#include<iostream>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  int count = 0;
  int r;
  int odd = 0;
  int even = 0;
  while (n > 0) {
    r = n%10;
    n = n/10;
    ++count;
    if ((count % 2) == 0) {
      even = even + r;
    }
    else odd = odd +r;
  }
  cout << odd << " " << even << endl;
  if (even == 0 or odd == 0) {
    cout << "0 = ";
    if (odd >= even) {
      cout << even << " * " << odd << endl;
    }
    if (even >= odd) {
      cout << odd << " * " << even << endl;
    }
  }
  else if (odd >= even) {
    if ((odd % even) == 0) {
      cout << odd << " = " << odd/even << " * " << even << endl;
    }
    else cout << "nothing" << endl;
  }
  else if (even >= odd) {
    if ((even % odd) == 0) {
      cout << even << " = " << even/odd << " * " << odd << endl;
    }
    else cout << "nothing" << endl;
  }
}