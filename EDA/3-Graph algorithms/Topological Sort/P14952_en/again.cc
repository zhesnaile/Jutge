#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

//1 <= n <= 10^4
//0 <= m <= 10*n
//
typedef vector<vector<int>> Graph;

list<int> topological_sort(Graph& G){
  int n = G.size();
  
  vector<int> predecessors(n, 0);
  for (int i = 0; i < n; ++i)
    for (auto j : G[i])
      ++predecessors[j];

  priority_queue<int, vector<int>, greater <int>> S;
  for (int i = n-1; i >= 0; --i)
    if (predecessors[i]==0) 
      S.push(i);

  list<int> L;
  while(!S.empty()){
    int aux = S.top();
    S.pop();
    L.push_back(aux);
    for (auto x : G[aux]) 
      if (--predecessors[x] == 0)
        S.push(x);
  }
  return L;
}

int main(){
  int n, m;
  while (cin >> n >> m){
    int x, y;
    Graph taskadj(n);
    for (int i = 0; i < m; ++i){
      cin >> x >> y;
      taskadj[x].push_back(y);
    }
    list<int> spititout = topological_sort(taskadj);
    for (list<int>::iterator it = spititout.begin(); it != spititout.end(); ++it){
      if (it != spititout.begin()) cout << ' ';
      cout << *it;
    }
    cout << endl;
  }
}
