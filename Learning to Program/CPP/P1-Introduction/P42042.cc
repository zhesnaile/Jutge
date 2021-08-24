#include <iostream>
using namespace std;

int main() {
    char c;
    cin >> c;
    if (c>=65 and c<=90){
        cout << "uppercase" << endl;
        if (c==65 or c==69 or c==73 or c==79 or c==85){
            cout << "vowel" << endl;
        }
        else {
            cout << "consonant" << endl;
        }
    }
    else if (c>=97 and c<=122){
        cout << "lowercase" << endl;
        if (c==97 or c==101 or c==105 or c==111 or c==117){
            cout << "vowel" << endl;
        }
        else {
            cout << "consonant" << endl;
        }
    }
}