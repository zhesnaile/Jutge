#include <iostream>
#include <set>
using namespace std;

int main(){
    string wurd;
    set<string> seq;
    set<string>::iterator it, mid;
    it = seq.begin();
    cin>>wurd;
    while (wurd != "END"){
        seq.insert(it, wurd);
        if (seq.size()==1) mid = seq.begin();
        if (wurd < *mid && seq.size()%2 == 0) --mid;
        else if (wurd > *mid && seq.size()%2 == 1) ++mid;
        cout << *mid << endl;
        cin>>wurd;
    }
}
