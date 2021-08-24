#include <iostream>
#include <map>
using namespace std;

int main(){
    int x, y, n;
    while (cin >> x >> y >> n){
        map<int, int> col_map;
        pair<map<int, int>::iterator, bool> ret;
        int i=0;
        ret = col_map.insert(make_pair(n, i));
        while (n<=100000000 && ret.second != false)
        {
            ++i;
            if (n%2==0) n = n/2 +x;
            else n=3*n + y;
            ret = col_map.insert(make_pair(n, i));
        }
        if (ret.second == false) n = (col_map.size() - (ret.first)->second);
        cout << n << endl;
    }
}
