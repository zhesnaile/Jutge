#include <iostream> 
using namespace std;

int main(){
    int n;
    cin >> n;
    if (n!=0){
        while (n > 0){
            int r = n%16;
            n /= 16;
            if (r<=9)
                cout << r;
            else if (r==10) cout << "A";
            else if (r==11) cout << "B";
            else if (r==12) cout << "C";
            else if (r==13) cout << "D";
            else if (r==14) cout << "E";
            else cout << "F";
        }
    }
    else cout << n;
    cout << endl;
}
