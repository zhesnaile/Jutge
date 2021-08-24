#include<iostream>
#include<vector>
using namespace std;

int position_maximum(const vector<double>& v, int m){
    int max=0;
    double max_val=v[0];
    for (int i = 0; i<=m; i++){
        if (v[i]>max_val){
            max = i;
            max_val = v[i];
        }
    }
    return max;
}