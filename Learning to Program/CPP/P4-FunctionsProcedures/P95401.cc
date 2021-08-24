#include <iostream>
using namespace std;

bool is_leap_year(int year){
    if ((year%4!=0) or (year%100==0 and year%400!=0)) return false;
    else return true;
}