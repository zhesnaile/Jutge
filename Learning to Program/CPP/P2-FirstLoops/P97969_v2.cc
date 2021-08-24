#include <iostream>
using namespace std;
 
 
int main() {
    char a;
    int c = 0;
    
    cin >> a;

    while(a!='.'){
        if (a== 'a') c= c+1;
        cin>>a;
    }
    cout << c << endl;
}