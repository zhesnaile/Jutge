#include <iostream>
using namespace std;

string day_of_the_week (int d, int m, int y){
    int c, a, f;
    m-=2;
    if (m<=0){
        m+=12;
        --y;
    }
    c=y/100;
    a=y%100;
    f=((2.6*m)-0.2);
    f+=d+a+(a/4)+(c/4)-(2*c);
    while (f<0) f+=7;
    if (f%7==0) return ("Sunday");
    else if (f%7==1) return ("Monday");
    else if (f%7==2) return ("Tuesday");
    else if (f%7==3) return ("Wednesday");
    else if (f%7==4) return ("Thursday");
    else if (f%7==5) return ("Friday");
    else return ("Saturday");
}

int main(){
    int a, b, c;
    cin>>a>>b>>c;
    cout<<day_of_the_week(a,b,c)<<endl;
}