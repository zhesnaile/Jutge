#include <iostream>
#include <map>
#include <string>
using namespace std;

//returns the output corresponding to the minimum as a string
string peasant(const map<string, int>& aux){
    return "minimum: " + aux.begin()->first + ", " + to_string(aux.begin()->second) + " time(s)";
}

//returns the output corresponding to the maximum as a string
string king (const map<string, int>& aux){
    return "maximum: " + aux.rbegin()->first + ", " + to_string(aux.rbegin()->second) + " time(s)";
}

int main(){
    map<string, int> bag;
    string order;
    while (cin>>order){
        if (order == "minimum?"){
            cout << (bag.empty() ? "indefinite minimum" : peasant(bag)) << endl;
        }
        else if(order == "maximum?"){
            cout << (bag.empty() ? "indefinite maximum" : king(bag)) << endl;
        }
        else{
            string elemento;
            cin >> elemento;
            auto x = bag.find(elemento);
            if(order == "store"){
                int n = 1;
                if (x != bag.end()) n+=bag[elemento];
                bag[elemento]=n;
            }
            else{
                if (x != bag.end()){
                    if (x->second!=1)--bag[elemento];
                    else bag.erase(x);
                } 
            }
        }
    }
}