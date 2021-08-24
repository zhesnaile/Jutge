#include<iostream>
#include<vector>
using namespace std;

bool resistant_search_rec(double x, const vector<double>& v, int left, int right){
    if (left > right) return 0;
    int mid=(left+right)/2;
    if(v[mid] == x || v[mid-1] == x || v[mid+1] == x || v[left] == x || v[right] == x) return true;
    else if (v[mid] < x) return resistant_search_rec(x, v,  mid+1, right);
    else return resistant_search_rec(x, v, left, mid+1);
}

bool resistant_search(double x, const vector<double>& v){
    return resistant_search_rec(x, v, 0, v.size()-1);
}

int main(){
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
                double x;
                cin >> x;
                cout << resistant_search(x, V) << endl;
        }
    }
}
