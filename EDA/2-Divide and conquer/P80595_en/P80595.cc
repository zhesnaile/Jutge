#include<iostream> 
#include<vector>
using namespace std;

int merge(vector<int> &v, int l, int m, int r){
    vector<int> z(r-l+1);
    int i = l, j = m+1, k=0;
    int count = 0;
    while (i <= m && j<=r){
        if (v[i] <= v[j]) z[k++]=v[i++];
        else{
            z[k++]=v[j++];
            count += m+1-i;
        }
    }
    while (i <= m) z[k++] = v[i++];
    while (j <= r) z[k++] = v[j++];
    for (k = 0; k < z.size(); ++k) v[l+k] = z[k];
    return count;
}

int merge(vector<int> &v, int l, int r){
    int count = 0;
    if (l < r){
        int m = (l+r)/2;
        count = merge(v, l, m);
        count += merge(v, m+1, r);
        count += merge(v, l, m, r);
    }
    return count;
}

int main(){
    int n;
    while(cin>>n){
     vector<int> orig_vec(n);
     for (int i = 0; i<n; ++i) cin>>orig_vec[i];
     cout << merge(orig_vec, 0, n-1) << endl;
    }
}
