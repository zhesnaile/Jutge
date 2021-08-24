#include <iostream>
using namespace std;

int main(){
    int a, b, s=0;
    while (cin>>a){
        for(int i=0; i<a; ++i){
            cin>>b;
            if (s<b or i==0) s=b;
        }
        cout << s << endl;
    }
}