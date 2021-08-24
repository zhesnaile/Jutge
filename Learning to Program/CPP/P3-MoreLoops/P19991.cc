#include <iostream>
using namespace std;
 
int main () {
        int a1,a=1,t=0;
        string n;
        cin >> a1;
        while (a<=a1) {
            cin >> n;
            t = t + (n[a-1] - 48) + (n[a1-a] - 48);
            if ((a-1) == (a1-a)) t=t-(n[a-1]-48);
            a++;
        }
        cout << t << endl;
    }