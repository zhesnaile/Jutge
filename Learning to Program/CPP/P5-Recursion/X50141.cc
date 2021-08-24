#include<iostream>
using namespace std;

int engreixa (int x) {
	if (x < 10) return x;
	int engr = engreixa(x/10);
	int udengr = engr%10;
	int d = x%10;
	int m = max(udengr,d);
	return engr*10 + m;
}