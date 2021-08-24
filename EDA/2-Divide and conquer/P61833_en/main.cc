#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int>> matrix;

void mult(const matrix& M1, const matrix& M2, matrix& p, int m)
{
    p=matrix(2, vector<int>(2));
    p[0][0]=(M1[0][0]*M2[0][0] + M1[0][1]*M2[1][0])%m;
    p[0][1]=(M1[0][0]*M2[0][1] + M1[0][1]*M2[1][1])%m;
    p[1][0]=(M1[1][0]*M2[0][0] + M1[1][1]*M2[1][0])%m;
    p[1][1]=(M1[1][0]*M2[0][1] + M1[1][1]*M2[1][1])%m;
}

void puis(const matrix& mat, int n, int m, matrix& mat2){
    if (n == 0) {
        mat2[0][0] = mat2[1][1] = 1;
        mat2[0][1] = mat2[1][0] = 0;
    } else {
        matrix aux(2, vector<int>(2));
        if(n==1){
            aux[0][0] = aux[1][1] = 1;
            aux[0][1] = aux[1][0] = 0;
            mult(mat,aux, mat2, m);
        } else if (n%2 == 0) {
            puis(mat, n/2, m, aux);
            mult(aux, aux, mat2, m);
        } else {
            puis(mat, n-1, m, aux);
            mult(mat, aux, mat2, m);
        }
    }
}

int main(){
	matrix mat(2, vector<int>(2));
	int n, m;
	while (cin >> mat[0][0] >> mat[0][1] >> mat[1][0] >> mat[1][1] >> n >> m){
		matrix mat2(2, vector<int>(2));
		puis(mat, n, m, mat2);
		cout << mat2[0][0] << ' ' << mat2[0][1] << "\n" << mat2[1][0] << ' ' << mat2[1][1] << "\n";
		cout << "----------" << endl;
	}
}
