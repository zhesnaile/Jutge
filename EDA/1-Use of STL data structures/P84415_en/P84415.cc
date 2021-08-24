#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    string inst;
    map<string,int> bag;
    auto it = bag.begin();
    while (cin >> inst) {
        if (inst == "minimum?" or inst == "maximum?") {
            inst.pop_back();
            if (bag.empty()) 
                cout << "indefinite " << inst << endl;
            else{
                if (inst == "maximum"){
                    it = bag.end();
                    --it;
                }
                else it = bag.begin();
                cout << inst << ": " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
        else {
            string h;
            cin >> h;
            it = bag.find(h);
            if (inst == "store") {
                bag.insert(make_pair(h, 0));
                ++bag[h];
            }
            else {
                if (it != bag.end()) {
                    --(it->second);
                    if (it->second == 0) bag.erase(it);
                }
            }
        }
    }
}
