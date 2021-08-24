#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Graph;

bool DFS_recursive(Graph& G, vector<int>& visited, int current, int father){
  if (visited[current] != -1){
    if ( visited[current] == visited[father] && (current != father)) return true;
    else return false;
  }
  else {
    visited[current]=(visited[father]+1)%2;
    bool help=0;
    int tope = G[current].size();
    for (int i = 0; i<tope; ++i){
      help+=DFS_recursive(G, visited, G[current][i], current);
    }
    return help;
  }
} 

void DFS_function(Graph& G){
  vector<int> visited(G.size());
  for (int i=0; i<visited.size(); ++i){
    visited[i]=-1;
  }
  bool help=0;
  int i=0;
  int tope=G.size();
  while(i<tope && help==0){
     help+=DFS_recursive(G, visited, i, i);
     ++i;
  }
  if (help==false) cout << "yes" << endl;
  else cout << "no" << endl;
}


int main (){
  int n, m, x, y;
  while(cin>>n>>m){
    Graph aux(n);
    for (int i=0; i<m; ++i){
      cin>>x>>y;
      aux[x].push_back(y);
      aux[y].push_back(x);
    }
    DFS_function(aux);
  }
}
