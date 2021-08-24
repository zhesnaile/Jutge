#include <iostream>
#include <vector>
using namespace std;

typedef vector<bool> VB;
typedef vector<int> VE;
typedef vector<int> VBB;


int n, d;

VB en_uso;
VE mi_solucion;

bool is_dbalanced(int x, int y){
    int a = y - mi_solucion[x];
    return( a <= d and a*(-1) <= d);
}

void d_balancing(int posicion){
    if (posicion == n){
        cout << '(';
        for (int i=0; i<n; ++i){
            if ( i != 0 ) cout << ',';
            cout << mi_solucion[i]+1;
        } 
        cout << ')' << endl;
    } else{
        for (int i = 0; i < n; ++i){
            if (not en_uso[i] && (posicion==0 or is_dbalanced(posicion-1, i ))){
                en_uso[i] = true;
                mi_solucion[posicion]=i;
                d_balancing(posicion+1);
                en_uso[i]=false;
            }
        }
    }
}

int main(){
    cin >> n >> d;
    en_uso = VB (n,false);
    mi_solucion = VE(n);
    d_balancing(0);
}
