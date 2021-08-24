#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>

using namespace std;

const int oo = INT_MAX;

typedef vector<int> VE;
typedef vector<vector<pair<int,int>>> Grafo;


int n, m;
Grafo rutas_disp;

int dijkstra(int x, int y){
    VE distancias(n, +oo);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>mi_pq;
    distancias[x]=0;
    mi_pq.push({0,x});
    while ( not mi_pq.empty() ){
        auto t = mi_pq.top();
        mi_pq.pop();
        int u = t.second;
        int d = t.first;
        if (u == y) return distancias[y];
        if (d == distancias[u]){
            for (auto p : rutas_disp[u]){
                int v = p.second;
                int l = p.first;
                int d2 = max(distancias[u], l);
                if (d2 < distancias[v]){
                    distancias[v] = d2;
                    mi_pq.push({d2, v});
                }
            }
        }
    }
    return +oo;
}

int main(){
    while (cin >> n >> m) {
        rutas_disp = Grafo(n);
        while (m--){
            int x , y, d;
            cin >> x >> y >> d;
            rutas_disp[x].push_back({d,y});
        }
        cout << dijkstra(0, 1) << endl;
//        for (int i = 0; i < n; ++i){
//            cout << i << ":\n";
//            for (auto j : rutas_disp[i])
//                cout << "   ciudad: " << j.second << "\n    distancia: " << j.first << endl;
//        }
    }
}
