#include<iostream>
#include<vector>
using namespace std;

//S sequence of increasing ints



int fpoint(vector<int>& S, int& a, int left, int right){
    if (left > right) return -1;
    int mid = (left+right)/2;
    if (S[mid]+a < mid+1) return fpoint(S, a, mid+1, right);
    else if (S[mid]+a > mid+1) return fpoint(S, a, left, mid-1);
    else{

    }
}

int main(){
    int S_size, counter = 1;
    while (cin>>S_size){
        vector<int> S;
        for (int i = 0; i < S_size; ++i) cin>>S[i];
        int m, a;
        cout << "Sequence #" << counter << '\n';
        for (int i = 0; i< m; ++i){
            cin>>a;
            int pos_sol = fpoint(S, a, 0, S_size-1);
            if (pos_sol == -1) cout << "no fixed point for " << a << '\n';
            else cout << "fixed point for " << a << ':' << pos_sol << '\n';
        }
        ++counter;
        cout << flush;
    }
}
