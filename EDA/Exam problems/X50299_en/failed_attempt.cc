#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

typedef vector<int> VE;
typedef vector<pair<int,int>> VP;
typedef vector<vector<pair<int,int>>> Grafo;
typedef vector<bool> VB;
typedef priority_queue<pair<int,int>, VP , greater<pair<int,int>>> PQ;

int n, m;
Grafo rutas_disp;
VB en_uso;
VE distancias;


//bool mi_orden(pair<int,int> A, pair<int,int> B){
//    if (A.first != B.first) return A.first < B.first;
//    return A.second < B.second;
//}
//
//void mi_quicksort(){
//    for (int i = 0; i<n; ++i){
//        sort(rutas_disp[i].begin(), rutas_disp[i].end(), mi_orden);
//    }
//}

//bool interesa(const int &ciudad, const int &l_ruta, const int &u ){
//    bool aux = (distancias[ciudad] == -1  or ( distancias[u] + l_ruta < distancias[ciudad]));
//    aux *= ;
//}

int cutre_dijkstra(PQ &mi_pq, int& curr_max){
    int local_max = 0;
    while (not mi_pq.empty()){
        int u=mi_pq.top().second;
        mi_pq.pop();
        if(not en_uso[u]){
            en_uso[u]=true;
            if (u==1) return distancias[u];
            for (auto x : rutas_disp[u]){
                int ciudad = x.second;
                int l_ruta = x.first;
                if (distancias[ciudad] == -1  or ( distancias[u] > l_ruta)){
                //if (interesa(ciudad, l_ruta, u)){
                    distancias[ciudad] = distancias[u] + l_ruta;
                    mi_pq.push({l_ruta, ciudad});
                }
            }
        }
    }
    return -1;
}

int max_camino(){
    PQ mi_pq;
    mi_pq.push({0,0});
    //cout << "Shortest path : " << cutre_dijkstra(mi_pq) << endl;
    //aux = distancia maxima+1
    int aux = 100001;
    cutre_dijkstra(mi_pq, aux);
    //cout << aux << endl;
    //cout << distancias[1] << endl;
    //while (not mi_pq.empty()){
    //    int x = mi_pq.top().first;
    //    mi_pq.pop();
    //    if (aux < x) aux=x;
    //}
    return aux;
}

//ciudad 0 --> 1 ruta mas corta.
//imprimir distancia del camino mas largo de la ruta.
int main(){
    while (cin >> n >> m) {
        rutas_disp = Grafo(n);
        while (m--){
            int x , y, d;
            cin >> x >> y >> d;
            rutas_disp[x].push_back({d,y});
            //cout << x << ' ' << y << ' ' <<  d << endl;
        }
        //mi_quicksort();
        en_uso = VB(n, false);
        distancias = VE (n, -1);
        distancias[0] = 0;
        
        for (int i = 0; i < n; ++i){
            cout << i << ":\n";
            for (auto j : rutas_disp[i])
                cout << "   ciudad: " << j.second << "\n    distancia: " << j.first << endl;
        }
        
        //cout << max_camino() << endl;
        max_camino();
    }
}
