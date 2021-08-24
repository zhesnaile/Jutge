#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

typedef vector<pair<int, int>> VE;
typedef vector<VE> VVE;

//1 <= n <= 10^4
//0 <= m <= 5n


int dijkstra(VVE& G, int source, int dest){
  vector<int> distances(G.size(), 500000001);
  vector<bool> visited(G.size(), false);
  priority_queue<pair <int, int>, VE , greater <pair <int, int>>> Q;
  Q.push({0, source});
  distances[source] = 0;

  while (!Q.empty()){
    int aux = Q.top().second;
    Q.pop();
    if (!visited[aux]){
      visited[aux]=true;
      for (auto help : G[aux]){
        int total_distance = (distances[aux]+help.second);
        if (distances[help.first] > total_distance){
          distances[help.first] = total_distance;
          Q.push({total_distance, help.first});
        }
      }
    }
  }
  return distances[dest];
}

int main(){
  int n, m;
  while (cin>>n>>m){
    VVE adj(n);
    int u, v, c;
    for (int i = 0; i < m; ++i){
      cin >> u >> v >> c;
      adj[u].push_back({v,c});
    }
    int x, y;
    cin>>x>>y;
    int res = dijkstra(adj, x , y);
    if (res != 500000001) cout << res <<endl;
    else cout << "no path from " << x << "to " << y << endl;
  }
}
