#include<iostream>
#include<vector>
#include<set>
#include<limits.h>
using namespace std;

long suma;
set<int> general;
set<int> mis_joyas;

void imprime_maximo(const set<int>& mis_joyas, int &n){
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

void es_interesante(const int& x, const int& n){
    auto it = mis_joyas.begin();
    int aux = mis_joyas.size();
    if ( aux < n or x > *it){
        if (aux >= n )mis_joyas.erase(it);
        mis_joyas.insert(x);
        suma+=x;
    }
    else general.insert(x);
}

void era_interesante(int& x){
    auto it = mis_joyas.find(x);
    if (it != mis_joyas.end() ){
        suma -=x;
        mis_joyas.erase(it);
    }
}

int main(){
    int n;
    cin >> n;
    string instruccion;
    int valor;
    suma = 0;
    while (cin >> instruccion >> valor){
        if (instruccion == "leave") {
            es_interesante(valor, n);
        }
        else era_interesante(valor);
        cout << suma << endl;
        //imprime_maximo(mis_joyas, n);
    }
}
