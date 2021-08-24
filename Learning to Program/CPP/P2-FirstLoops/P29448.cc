#include <iostream>
using namespace std;

int main(){
    int d, m, y;
    while (cin >> d >> m >> y){
        if (d<1 or d>31){
            cout << "Incorrect Date" << endl;
        }
        else if (m<1 or m>12)
                cout << "Incorrect Date" << endl;
        else if((m==4 or m==6 or m==9 or m==11) and d==31)
                cout << "Incorrect Date" << endl;
        else if (m==2){
            if (d>29)
                cout << "Incorrect Date" << endl;
            else if ((y%4==0) and (d==29)){
                if ((y%100==0) and y%400!=0)
                    cout << "Incorrect Date" << endl;
                else 
                    cout << "Correct Date" << endl;
            }
            else if ((y%4!=0) and (d==29))
                cout << "Incorrect Date" << endl;
            else 
                cout << "Correct Date" << endl;
        }
        else 
            cout << "Correct Date" << endl;
    }
}