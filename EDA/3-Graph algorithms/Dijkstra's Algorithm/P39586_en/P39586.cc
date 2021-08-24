#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

typedef vector <pair <int, int>> VE;
typedef vector<VE> VVE;

//1 <= n <= 10^4
//0 <= m <= 5n

void dijkstra(VVE& G, int source, int dest){
  int n = G.size();
  vector<bool> visited(n, 0);
  vector<int> distances(n, 500000001);
  vector<int> paths(n, 0);
  priority_queue <pair <int, int>, VE, greater <pair <int, int>>> Q;
  Q.push({0, source});
  distances[source]=0;
  paths[source]=1;
  while (!Q.empty()){
    int aux = Q.top().second;
    Q.pop();
    if(!visited[aux]){
      visited[aux]=true;
      for (auto help : G[aux]){
        int total_distance = (distances[aux]+help.second);
        if (distances[help.first] > total_distance){
          paths[help.first] = paths[aux];
          distances[help.first] = total_distance;
          Q.push({total_distance, help.first});
        }
        else if (distances[help.first] == total_distance) paths[help.first] += paths[aux];
      }
    }
  }
  if (distances[dest] == 500000001)
    cout << "no path from " << source << " to " << dest << endl;
  else
    cout << "cost " << distances[dest] << ", " << paths[dest] << " way(s)" << endl;
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
    dijkstra(adj, x, y);
  }
}
