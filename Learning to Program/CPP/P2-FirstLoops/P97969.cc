#include <iostream>
#include <string>
using namespace std;
 
int main(){
        string s;
        cin >> s;
        int i = 0;
        int aux = 0;
        while (s[aux] != '.'){
                if(s[aux] == 'a') ++i;
                ++aux;
        }
        cout << i << endl;
}