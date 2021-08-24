#include <stack>
#include "eda.hh"
#include "graph.hh"
list<int> topological_sort(const graph& G) {
    int n = G.size();
    vector<int> ge(n, 0);
    for (int u = 0; u < n; ++u) {
        for (int v : G[u]) {
	    ++ge[v];
	}
    }
    stack<int> S;
    for (int u = 0; u < n; ++u) {
        if (ge[u] == 0) {
	    S.push(u);
	}
    }
    list<int> L;
	while (not S.empty()) {
    	    int u = S.top(); S.pop();
            L.push_back(u);
	    for (int v : G[u]) {
		if (--ge[v] == 0) {
		    S.push(v);
		}
	    }
	}
    return L;
}
