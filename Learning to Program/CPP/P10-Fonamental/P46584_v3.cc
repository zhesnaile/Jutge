#include <iostream>
#include <vector>
using namespace std;

vector<double> difference(const vector<double>& v1, const vector<double>& v2){
    int n=v1.size(), m=v2.size();
    vector<double> aux;
    for (int i=0; i<n; ++i){
        bool k=0;
        for (int a=0; a<m && k==0; ++a){
            if (v1[i]==v2[a]) k=1;
        }
        if (k==0) aux.push_back (v1[i]);
    }
    vector<double> v3(aux.size());
    for (int i=0; i<aux.size()-1; ++i){
        if (v3[i]!=aux[i+1]) v3[i]=aux[i];
    }
    return v3;
}
int main(){
    vector<double> v1(6);
    v1[0]=1;
    v1[1]=2;
    v1[2]=2;
    v1[3]=5;
    v1[4]=5;
    v1[5]=7;
    vector<double> v2(4);
    v2[0]=2;
    v2[1]=3;
    v2[2]=3;
    v2[3]=7;
    int x=difference(v1, v2).size();
    for (int i=0; i<x-1; ++i) cout << difference(v1,v2)[i]<<", ";
    cout << difference(v1,v2)[x-1] << endl;
}