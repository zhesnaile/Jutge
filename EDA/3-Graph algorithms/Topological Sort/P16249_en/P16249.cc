#include<iostream>
#include<vector>
#include<stack>
#include<list>
#include<set>
using namespace std;

typedef map<string, vector<string>> 

vector <string> my_topo_sort(vector<string> &Vbasic, vector<pair<string,string>> &Vprecedencies){
    int n = Vbasic.size();
    vector<string> ge(n, " ");
    for (int s = 0; s < n; ++s){
        
    }
}



int main(){
    // n = num_tasks
    // input n times task names
    // m = num of dependencies
    // m pairs x y where x precedes y
    int n;
    while (cin >> n){
        vector<string> verbose_bag(n);
        string ajudam;
        for (int i = 0; i < n; ++i) {
            cin>>verbose_bag[i];
        }
        int m; cin>>m;
        vector<pair<string, string>> precedencies;
        string x, y;
        for (int i = 0; i < m; ++i){
            cin >> x >> y;
            precedencies[i] = {x, y};
        }
        vector <string> sorted = my_topo_sort(verbose_bag, precedencies);
    }
}
