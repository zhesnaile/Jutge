#include <iostream>
using namespace std;

int main() {
    int n, m, x=0;
    while (cin >> n >> m){
        int f=9;
        if (x!=0) cout << endl;
        for (int a=0; a<n; a++){
            for (int b=0; b<m; b++) {
                cout << f;
                if (f!=0) f-=1;
                else f=9;
            }
            cout << endl;
        }
        x++;
    }
}