#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Grid;
typedef vector<vector<bool>> aux_Grid;

bool in_range(const Grid &G, const int &pos_row, const int &pos_col) {
  return (pos_row < G.size() && pos_row > 0) &&
         (pos_col < G[1].size() && pos_col > 0);
}

bool traverse_map(const Grid &G, aux_Grid &visited, int pos_row, int pos_col) {
  if (in_range(G, pos_row, pos_col)) {
    if (visited[pos_row][pos_col] == 0) {
      visited[pos_row][pos_col] = 1;
      bool help = 0;
      if (G[pos_row][pos_col] == 't')
        help = 1;
      else if (G[pos_row][pos_col] == '.') {
        help += traverse_map(G, visited, pos_row + 1, pos_col);
        help += traverse_map(G, visited, pos_row - 1, pos_col);
        help += traverse_map(G, visited, pos_row, pos_col + 1);
        help += traverse_map(G, visited, pos_row, pos_col - 1);
      }
      return help;
    }
  }
  return false;
}

bool traverse_map(const Grid &G, int pos_row, int pos_col) {
  int num_rows = G.size();
  int num_cols = G[1].size();
  aux_Grid visited(num_rows, vector<bool>(num_cols, 0));
  return traverse_map(G, visited, pos_row, pos_col);
}

int main() {
  int x, y, ini_row, ini_col;
  cin >> y >> x;
  Grid treasure_map(y + 1, vector<char>(x + 1));
  for (int i = 1; i <= y; ++i)
    for (int j = 1; j <= x; ++j)
      cin >> treasure_map[i][j];
  cin >> ini_row >> ini_col;
  cout << (traverse_map(treasure_map, ini_row, ini_col) ? "yes" : "no") << endl;
}
