#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<bool> VVB;
typedef vector<VS> VSS;

int n, p;
VS mi_input;
VSS solucion_act;

void dividimos(int posicion){
    if (posicion < n){
        for (int j = 0; j < p; ++j){
            solucion_act[j].push_back(mi_input[posicion]);
            dividimos(posicion+1);
            solucion_act[j].pop_back();
        }
    }
    else {
        for (int i = 0; i < p; ++i){
            cout << "subset " << i+1 << ": {";
            int size_act = solucion_act[i].size();
            for (int j=0; j < size_act; ++j){
                if ( j!=0) cout << ',';
                cout << solucion_act[i][j];
            }
            cout << "}\n";
        } 
        cout << endl;
    }
}

int main(){    
    cin >> n;
    mi_input=VS(n);
    for (int i = 0; i < n; ++i)
        cin >> mi_input[i];
    cin >> p;
    solucion_act = VSS(p);
    dividimos(0);
}
