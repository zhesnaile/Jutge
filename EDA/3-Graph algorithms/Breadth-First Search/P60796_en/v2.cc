#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

typedef vector<vector<char>> Graph;

int BFS_operation(Graph& daboard, int x, int y){
  vector<vector<bool>> visited(daboard.size(), vector<bool>(daboard[0].size(), 0));
//  for (int i = 0; i < daboard.size(); ++i)
//    for (int j = 0; j < daboard[0].size(); ++j)
//      visited[i][j]=-1;
  queue<pair<pair<int,int>,int>> Q;
  Q.push({{x, y}, 0});
  int v, s, d;
  while (!Q.empty()){
    v = (Q.front().first).first;
    s = (Q.front().first).second;
    d = Q.front().second;
    Q.pop();

    if (daboard[v][s] == 't' ) return d;
    else if (!visited[v][s]){
      visited[v][s] = true;
      if (v != 0 && daboard[v-1][s] != 'X') Q.push({{v-1,s},d+1});
      if (v != daboard.size()-1 && daboard[v+1][s] != 'X') Q.push({{v+1, s}, d+1});
      if (s != 0 && daboard[v][s-1] != 'X') Q.push({{v, s-1}, d+1});
      if (s != daboard[0].size()-1 && daboard[v][s+1] != 'X') Q.push({{v, s+1}, d+1});
    }
  }
  return -1;
}

int main(){
  int n, m;
  cin >> n >> m;
  Graph Playboard (n, vector<char>(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> Playboard[i][j];
  int x, y;
  cin >> x >> y;
  int cheese = BFS_operation(Playboard, x-1, y-1);
  if (cheese != -1) cout << "minimum distance: " << cheese << endl;
  else cout << "no treasure can be reached" << endl;
}
