#include<iostream>
using namespace std;

int suma_digits(int x) {
	if (x < 10) return x;
	return suma_digits(x/10) + x%10;
}

int reduccio_digits(int x) {
	int resultat = x;
	while (resultat >= 10) {
		resultat = suma_digits(resultat);
	}
	return resultat;
}