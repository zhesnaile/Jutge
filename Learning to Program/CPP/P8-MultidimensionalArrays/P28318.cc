#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> Row;
typedef vector<Row> Matrix;

void read_matrix(Matrix& a){
    int rows=a.size();
    int columns=a[0].size();
    for (int i=0; i<rows; ++i){
        for (int j=0; j<columns; ++j){
            cin>>a[i][j];
        }
    }
}

void find_rows(Matrix& b, int a){
    int y=b[0].size();
    cout<<"row "<<a<<':';
    for (int o=1; o<=y; ++o) cout << ' ' << b[a][o];
    cout << endl;
}

void find_column(Matrix& b, int a){
    int g=b.size();
    cout<< "column " << a << ':';
    for (int o=1; o<=g; ++o) cout<<' '<< b[o][a];
    cout << endl;
}

void find_element(Matrix& b, int a, int d){
    cout << "element " << a << ' ' << d << ": " << b[a][d] << endl;
}
int main(){
    int n, m;
    cin >> n >> m;
    Matrix c(n,Row(m));
    read_matrix(c);
    string p;
    while (cin>>p){
        if (p=="row"-0){
            int x;
            cin>>x;
            find_rows(c, x);
        }
        else if (p=="column"-0){
            int x;
            cin>>x;
            find_column(c, x);
        }
        else if (p=="element"-0){
            int x, y;
            cin>>x>>y;
            find_element(c, x, y);
        }
    }
}