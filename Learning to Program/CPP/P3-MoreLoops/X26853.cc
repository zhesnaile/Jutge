#include <iostream>
using namespace std;

int main() {
    int n, m, x=0;
    while (cin >> n >> m){
        if (x!=0) cout << endl;
        for (int a=0; a<n; a++){
            for (int b=0; b<m; b++) cout << (n+m)%5;
            cout << endl;
        }
        x++;
    }
}