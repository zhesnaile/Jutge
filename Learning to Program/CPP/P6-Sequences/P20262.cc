#include <iostream>
using namespace std;

int main() {
        int x, y;
        while (cin >> x) {
                int inisum = 0;
                int inisummax = 0;
                int finalsum = 0;
                int finalsummax = 0;
                while (x > 0) {
                        cin >> y;
                        inisum = inisum + y;
                        if (inisummax < inisum) inisummax = inisum;    
                        finalsum = finalsum + y;
                        if (finalsum < 0) finalsum = 0;
                        finalsummax = finalsum;      
                        --x;
                }
                cout << inisummax << " " << finalsummax << endl;
        }
}