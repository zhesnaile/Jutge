#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef vector<vector<char>> Graph;

vector<vector<bool>> visited;

int treasure_hunt(Graph &G, stack<pair<int, int>> &route);

int treasure_hunt(Graph &G, int pos_row, int pos_col) {
  stack<pair<int, int>> route;
  route.push({pos_row, pos_col});
  int counter = 0;
  treasure_hunt(G, route);
  return counter;
}

int main() {
  int n, m, ini_row, ini_col;
  cin >> n >> m;
  Graph treasure_map(n + 1, vector<char>(m + 1));
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      cin >> treasure_map[i][j];
  cin >> ini_row >> ini_col;
  cout << treasure_hunt(treasure_map, ini_row, ini_col);
}
