#include <iostream>
#include <vector>
using namespace std;

bool anagram(vector<int>& a, vector <int>& b){
    if (a==b) return true;
    else return false;
}
int main(){
    int n;
    const int M= int('Z') - int('A') + 1;
    cin>>n;
    for (int i=0; i<n; ++i){
        vector<int> v1(M,0);
        char c;
        cin>>c;
        while (c!='.'){
            if (c>= 'A' and c<='Z') ++v1[int(c)-int('A')];
            cin >> c;
        }
        vector<int> v2(M,0);
        char e;
        cin>>e;
        while (e!='.'){
            if (e>= 'A' and e<='Z') ++v2[int(e)-int('A')];
            cin >> e;
        }
        cout << (anagram(v1, v2) ? "YES" : "NO") << endl; 
    }
}