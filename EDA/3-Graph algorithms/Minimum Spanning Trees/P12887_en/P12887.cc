#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

typedef pair<int, int> edge;
typedef vector<edge> VEadj;
typedef vector<VEadj> VVEadj;

int min_spin_trees(const VVEadj& G){
  int n = G.size();
  vector<bool> visited (n, false);
  visited[0] = true;
  priority_queue<edge, VEadj, greater <edge>> Q;
  for (auto eeee : G[0]) Q.push(eeee);
  int sz = 1;
  int sum = 0;
  while (sz < n){
    int aux = Q.top().second;
    int dist = Q.top().first;
    Q.pop();

    if( !visited[aux] ){
      visited[aux]=true;
      for (edge eeee : G[aux]) Q.push(eeee);
      sum += dist;
      ++sz;
    }
  }
  return sum;
}

int main(){
  int n, m;
  while (cin >> n >> m){
    VVEadj Gadj(n);
    int u, v, w;
    for (int i = 0; i < m; ++i){
      cin>>u>>v>>w;
      Gadj[u-1].push_back({w, v-1});
      Gadj[v-1].push_back({w ,u-1});
    }
    int answer = min_spin_trees(Gadj);
    cout << answer << endl;
  }
}
