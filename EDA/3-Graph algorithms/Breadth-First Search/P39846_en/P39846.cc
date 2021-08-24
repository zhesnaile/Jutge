#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

typedef vector<vector<char>> graphchar;
typedef vector<vector<bool>> graphbool;

int BFS_Furthest(graphchar& playboard, int ini_x, int ini_y){
  graphbool visited(playboard.size(), vector<bool> (playboard[0].size(), false));
  queue<pair<pair<int,int>,int>> Q;
  Q.push({{ini_x, ini_y}, 0});
  stack<int> s;
  s.push(-1);

  int x, y, d;
  while (!Q.empty()){
    x = (Q.front().first).first;
    y = (Q.front().first).second;
    d = Q.front().second;
    Q.pop();
    if (!visited[x][y]){
      visited[x][y] = true;
      if (playboard[x][y] == 't') s.push(d);
      if (x != 0 && playboard[x-1][y] != 'X') Q.push({{x-1, y}, d+1});
      if (x != playboard.size()-1 && playboard[x+1][y] != 'X') Q.push({{x+1, y}, d+1});
      if (y != 0 && playboard[x][y-1] != 'X') Q.push({{x, y-1}, d+1});
      if (y != playboard[0].size()-1 && playboard[x][y+1] != 'X') Q.push({{x, y+1}, d+1});
    }
  }
  return s.top();
}

int main(){
  int n, m, x, y;
  cin>>n>>m;
  graphchar usableboard(n, vector<char> (m));
  for (int i=0; i<n; ++i)
    for (int j=0; j<m; ++j)
      cin>>usableboard[i][j];
  cin>>x>>y;
  int intimate = BFS_Furthest(usableboard, x-1, y-1);
  if (intimate != -1) cout << "maximum distance: " << intimate << endl;
  else cout << "no treasure can be reached" << endl;
}
