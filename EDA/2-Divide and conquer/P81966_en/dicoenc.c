#include <stdio.h>

int position(double x, double v[], int esq, int dre){
    if (esq > dre) return -1;
    int mid = (esq+dre)/2;
    if (v[mid] > x) return position(x, v, esq, mid-1);
    if (v[mid] < x) return position(x, v, mid+1, esq);
    return mid;
}

int main() {
	int n, t;
	while (scanf("%d", &n) > 0) {
    double v[n];
    for (int i = 0; i < n; ++i) scanf("%lf", &v[i]);
    scanf("%d", &t);
    while (t) {
      --t;
      double x;
      int esq, dre;
      scanf("%lf %d %d", &x, &esq, &dre);
      printf("%d\n", position(x, v, esq, dre));
    }
	}
	return 0;
}
