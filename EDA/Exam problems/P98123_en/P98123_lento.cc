#include<iostream>
#include<vector>
#include<set>
#include<limits.h>
using namespace std;

struct mi_operator{
    bool operator ()(int a, int b){
        return a > b;
    }    
};


void imprime_maximo(const set<int, mi_operator>& mis_joyas, int &n){
    long suma, counter;
    suma = 0;
    counter = 0;
    auto it = mis_joyas.begin();
    while (counter < n && it != mis_joyas.end() ){
        suma += *it;
        ++it;
        ++counter;
    }
    cout << suma << endl;
}

int main(){
    int n;
    cin >> n;
    set<int, mi_operator> mis_joyas;
    string instruccion;
    int valor;    
    while (cin >> instruccion >> valor){
        if (instruccion == "leave") mis_joyas.insert(valor);
        else mis_joyas.erase(valor);
        imprime_maximo(mis_joyas, n);
    }
}
