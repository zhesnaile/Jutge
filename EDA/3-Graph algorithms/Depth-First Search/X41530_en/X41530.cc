#include<iostream>
#include<vector>
using namespace std;

void cerca_cicles(const vector <vector <int> >& adj, vector <bool>& vis, int i, int pare, bool& b) {
    if(!vis[i]){
        vis[i]=true;
        for (int aresta: adj[i]){
                if (aresta != pare) cerca_cicles(adj, vis, aresta, i, b);
                if (b) return;
        } 
    }
    else b=true;
}

void dfs(const vector<vector<int>>& adj){
    vector <bool> vis(adj.size(), false);
    int arbres = 0;
    for (int i=0; i<adj.size(); ++i){
        if (!vis[i]){
            bool b = false;
            cerca_cicles(adj, vis, i, i, b);
            if (b){
                cout << "no" << endl;
                return;
            }
            else ++arbres;
        }
    }
    cout << arbres << endl;
}

int main(){
    int n, m, x, y;
    while ( cin >> n >> m ){
        vector<vector<int>> touching(n);
        for (int i=0; i<m ; i++)
        {
            cin>>x>>y;
            touching[x].push_back(y);
            touching[y].push_back(x);
        }
        dfs(touching);
    }
}
