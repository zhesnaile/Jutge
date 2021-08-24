#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    string name, inst;
    map<string, int> plog;
    while (cin >>name >> inst){
        if (inst == "enters") {
            if (plog.find(name) != plog.end()) cout << name << " is already in the casino" << endl;
            else plog[name]=0;
        }
        else if (inst == "leaves") {
            if (plog.find(name) == plog.end()) cout << name << " is not in the casino" << endl;
            else {
                cout << name << " has won " << plog[name] << endl;
                plog.erase(name);
            }
        }
        else {
            int curr; 
            cin>>curr;
            if (plog.find(name) == plog.end()) cout << name << " is not in the casino" << endl;
            else plog[name]+=curr;
        }
    }
    cout << "----------" << endl;
    map<string,int>::const_iterator it = plog.begin();
    while (it!= plog.end()){
        cout << it->first << " is winning " << it->second << endl;
        ++it;
    }
}
