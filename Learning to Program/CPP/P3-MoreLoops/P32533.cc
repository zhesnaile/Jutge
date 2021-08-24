#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for (int a=0; a<n; a++){
        for (int b=1; b<n-a; b++) cout << '+';
        cout << '/';
        for (int b=0; b<a; b++) cout << '*';
        cout << endl;
    }
}