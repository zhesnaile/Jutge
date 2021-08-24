#include <iostream>
using namespace std;

bool is_valid_date(int d, int m, int y){
    if ((d<1 or d>31) or (m<1 or m>12) or ((m==4 or m==6 or m==9 or m==11) and d==31))return false;
    else if (((m==2) and (d>29)) or (((m==2) and d==29) and ((y%4!=0) or (y%100==0 and y%400!=0)))) return false;
    else if (((m==2) and d==29 and y%4==0) and (y%100!=0 or  (y%100==0 and y%400==0))) return true;
    else return true;
}
int main(){
    int d, m, y;
    cin>>d>>m>>y;
    cout<< is_valid_date(d, m, y) << endl;
}