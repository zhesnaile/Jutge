#include <iostream>
using namespace std;

int main(){
    int a, b, i=0;
    bool s=false;
    cin>>a;
    while(cin>>b and s==false){
        ++i;
        if (a>=i or b==-1){
            s=true;
            if (a==i) cout << "At the position " << a << " is a(n) " << b <<'.' << endl;
            else cout << "Incorrect position." << endl;
        }
    }
}