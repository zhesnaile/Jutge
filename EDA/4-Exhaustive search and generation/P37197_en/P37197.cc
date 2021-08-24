#include<iostream>
#include<vector>
using namespace std;

typedef vector<bool> VB;
typedef vector<vector<bool>> VVB;


//tamaño input
int n;
//matriz de animales que no pueden estar juntos (usando ids);
VVB mi_matriz(52, VB(52, false));
//vector de bools en uso
VB en_uso;
//vector con el intento de solucion actual (guardado con id's);
vector<int> solucion_act;
//vector con el input
vector<int> ids;

//letra a id, [A, Z] => [0, 25]; [a, z] => [26, 51];
int id_animal(char letra){
    if (letra >= 'A' &&  letra <= 'Z') return letra-'A';
    return letra - 'a' + 26;
}


//id a letra de animal, [0, 25] => [A, Z]; [a, z] => [26, 51];
char letra_animal(int id){
    if (id < 26) return 'A'+id;
    else return ('a' + id-26);
}

void mis_rutas(int posicion){
    //tamaño solucion <= deseado ==> aun no es valida.
    if (posicion < n){
        for (int j = 0; j < n; ++j){
            //en_uso[j] ? 
            //elemento anterior compatible con el actual ?
            if (not en_uso[j] && (posicion==0 or not mi_matriz[solucion_act[posicion-1]][ids[j]] )){
                solucion_act[posicion] = ids[j];
                en_uso[j]=true;
                mis_rutas(posicion+1);
                en_uso[j]=false;
            }
        }
    }
    //tamaño solucion == deseado ==> imprimimos solucion.
    else{
        for (int j = 0; j<n; ++j)
            cout << letra_animal(solucion_act[j]);
        cout << endl;
    }
}

int main(){
    cin>>n;
    ids = vector<int> (n);
    for (int i = 0; i < n; ++i){
        char letra;
        cin >> letra;
        ids[i] = id_animal(letra);
    }
    int m;
    cin >> m;
    //importante m-- en vez de --m o se saltara un ciclo
    while(m--){
        char a, b;
        cin >> a >> b;
        int x = id_animal(a);
        int y = id_animal(b);
        mi_matriz[x][y] = true;
        mi_matriz[y][x] = true;
    }
    en_uso = VB(n, false);
    solucion_act = vector<int>(n);
    mis_rutas(0);
}
