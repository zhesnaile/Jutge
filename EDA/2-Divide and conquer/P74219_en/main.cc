#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int>> matrix;

const matrix X({ { 1, 1 }, { 1, 0 } });

void mult(const matrix& M1, const matrix& M2, matrix& p, int m)
{
    for (int i=0; i<2; ++i){
        for (int j=0; j<2; ++j)
            p[i][j]=(M1[i][0]*M2[0][j] + M1[i][1]*M2[1][j])%m;
    }
}

void puis(const matrix& mat, int n, int m, matrix& mat2){
    if (n == 0) {
        mat2[0][0] = mat2[1][1] = 1;
        mat2[0][1] = mat2[1][0] = 0;
    } else {
        matrix aux(2, vector<int>(2));
        if (n%2 == 0) {
            puis(mat, n/2, m, aux);
            mult(aux, aux, mat2, m);
        } else {
            puis(mat, n-1, m, aux);
            mult(mat, aux, mat2, m);
        }
    }
}

int fibonacci(int n, int m) {
	if (n < 2) return n;
	matrix mat2(2, vector <int>(2));
	puis(X, n, m, mat2);
	return mat2[0][1];
}

int main() {
	int n;
	long m;
	while (cin >> n >> m)
		cout << fibonacci(n, m) << endl;
}
