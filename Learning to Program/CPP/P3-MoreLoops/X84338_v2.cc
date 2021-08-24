#include <iostream>
using namespace std;
 
int main(){
    int n,p1,p2;
    int counter=1;
    cin >> n;
    p1=n;
    while(p1/10>0){
        p1=p1/10;
        ++counter;
    }
    if((counter%2)!=0) cout << "nothing" << endl;
    else{
        p1=0;
        p2=0;
        counter=counter/2;
        while(counter>0){
            p1+=(n%10);
            n=n/10;
            --counter;
        }
        while(n>0){
            p2+=(n%10);
            n=n/10;
        }
 
        if (p1==p2) cout << p1 << " = " << p2 << endl;
        else if (p2>p1) cout << p2 << " > " << p1 << endl;
        else cout << p2 << " < " << p1 << endl;
    }
}