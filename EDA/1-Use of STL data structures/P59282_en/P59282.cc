#include<iostream>
#include<map>
using namespace std;

int main(){
    cout.setf(ios::fixed);
    cout.precision(4);
    map<int, int> statt;
    int min, max;
    int nume = 0;
    int div = 0;
    map<int, int>::iterator it;
    string help;
    while (cin >> help){
        if (help == "number"){
            pair<int, int> P;
            cin>>P.first;
            P.second = 1;
            it = statt.find(P.first);
            if (it != statt.end()) {
                    P.second = it->second;
                    ++P.second;
                    statt.erase(it);
            }
            statt.insert(P);
            nume += P.first;
            ++div;
        }
        else {
            if(not statt.empty()){
                it = statt.begin();
                pair<int, int> P (it->first, it->second);
                P.second -= 1;
                statt.erase(it);
                nume -= P.first;
                --div;
                if (P.second != 0) statt.insert(P); 
            }
        }
        if (not statt.empty()){
            it = statt.begin();
            min = it->first;
            it = statt.end();
            --it;
            max = it->first;
            double ave = double(nume)/double(div);
            cout << "minimum: " << min << ", maximum: " << max << ", average: " << ave << endl;
        }
        else cout << "no elements" << endl;
    }
}
