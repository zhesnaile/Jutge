#include <iostream> 
using namespace std;

int main() {
    char a, b;
    cin >> a >> b;
    if ((a==65 and b==80) or (a==80 and b==86) or (a==86 and b==65)){
        cout << '1' << endl;
    }
    else if((a==80 and b==65) or (a==86 and b==80) or (a==65 and b==86)){
        cout << '2' << endl;
    }
    else if (a==b){
        cout << '-' << endl;
    }
}