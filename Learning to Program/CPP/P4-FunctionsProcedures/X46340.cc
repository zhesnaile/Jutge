#include <iostream>
using namespace std;

int sum_min_max(int x, int y, int z) {
        int max, min;
        if (x >= y and x >= z) max = x;
        else if (y >= z) max = y;
        else max = z;
        if (x <= y and x <= z) min = x;
        else if (y <= z) min = y;
        else min = z;
        return max+min;
}

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << sum_min_max(a,b,c) << endl;
}