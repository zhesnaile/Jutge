#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Graph;


int bfs (const Graph& giraff, int ini_row, int ini_col){
  vector<vector<bool>> visited(giraff.size(), vector<bool> (giraff[0].size(), false));
  queue<pair<pair<int,int>,int>> Q;
  Q.push(make_pair(make_pair (ini_row, ini_col),0));
  int x, y, d;
  while (not Q.empty()){
    x = (Q.front().first).first;
    y = (Q.front().first).second;
    d = Q.front().second;
    if (giraff[x][y]=='t'){
      return visited[x][y];
    }
    for (auto w : dirs){
      int x = w.first+v.first;
      int y = w.second+v.first;
      if (0 < x && x < Max_row && 0 < y && y < Max_col){
        if (visited[x][y] == -1 && giraff[x][y]!='X') {
          visited[x][y] = visited[v.first][v.second] + 1;
          Q.push({x, y});
        }
      } 
    }
  }
  return -1;
//  int hello;
//  for (auto v : treasures){
//    if (hello > visited[v.first][v.second] || hello == -1) hello = visited[v.first][v.second];
//  }
//  return hello;
}


int main(){
  int n, m, x, y;
  cin >> n >> m;
  Graph usableboard(n, vector<char> (m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> usableboard[i][j];
  cin >> x >> y;
  int result = bfs(usableboard, x-1, y-1);
  if (result==-1) cout << "no treasure can be reached" << endl;
  else cout << "minimum distance " << result << endl;
}


//Hay que reescribirlo usando una lista de adyacencia en vez de "mapa" de vertices
//las lineas acerca de los tesoros pueden ser utiles para el p39846 con un poco de modificacion 
