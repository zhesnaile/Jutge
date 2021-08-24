#include <iostream>
#include <set>
using namespace std;

int main(){
    int x, y, n;
    while (cin >> x >> y >> n){
        set<int> col_seq;
        pair<set<int>::iterator, bool> ret;
        ret.second=true;
        while (n<=100000000 and ret.second != false)
        {
            ret = col_seq.insert(n);
            if (n%2==0) n = n/2 +x;
            else n=3*n + y;
        }
        if (ret.second == false) cout << col_seq.size() << endl;
        else cout << *(ret.first) << endl;
    }
}
