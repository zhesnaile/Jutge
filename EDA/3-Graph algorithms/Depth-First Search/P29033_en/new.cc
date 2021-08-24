#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef vector<vector<int>> int_matrix;

bool colour_me_rec(const int_matrix &pairings, vector<int> &colouring, int pos,
                   int father) {
  if (colouring[pos] == -1) {
    colouring[pos] = (colouring[father] + 1) % 2;
    bool all_of_these = true;
    for (auto &x : pairings[pos])
      all_of_these = all_of_these && colour_me_rec(pairings, colouring, x, pos);
    return all_of_these;
  } else {
    return not(colouring[pos] == colouring[father] && pos != father);
  }
}

bool colour_me(const int_matrix &pairings) {
  int n = pairings.size();
  vector<int> colouring(n, -1);
  int i = 0;
  bool aux = 1;
  while (i < n && aux == 1) {
    aux &= colour_me_rec(pairings, colouring, i, i);
    ++i;
  }
  return aux;
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    int_matrix pairings(n);
    int x, y;
    for (int i = 0; i < m; ++i) {
      cin >> x >> y;
      pairings[x].push_back(y);
      pairings[y].push_back(x);
    }
    cout << (colour_me(pairings) ? "yes" : "no") << endl;
  }
}
