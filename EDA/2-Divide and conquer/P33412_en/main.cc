#include <iostream>
#include <vector>
using namespace std;


bool resistant_search(double x, const vector<double>& v){
    if (v.size() == 0) return false;
    int left = 0, right=v.size()-1, mid;
    while(left+1 < right){
        mid =(left + right)/2;
        if (v[mid]==x or v[mid-1]==x or v[mid+1]==x) return true;
        else if (v[mid] < x) left = mid;
        else right = mid;
    }
    return (v[left]==x or v[right]==x);
}


int main() {
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
