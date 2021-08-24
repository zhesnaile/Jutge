#include <iostream>
using namespace std;
 
struct Rational {
         int num, den;
     };
   
int gcd (int n, int d) {
    int r = 0;
    if(d == 0)
        return n;
    else {
        r = gcd(d, n%d);
    }
    return r;
}
 
void add (Rational& nbr) {
  Rational nbr2;
  cin >> nbr2.num >> nbr2.den;
  Rational result;
  result.num = (nbr.num * nbr2.den)+ ( nbr2.num * nbr.den);
  result.den = nbr.den * nbr2.den;
   
  nbr = result;
}
 
void substract (Rational& nbr) {
  Rational nbr2;
  cin >> nbr2.num >> nbr2.den;
  Rational result;
  result.num = (nbr.num * nbr2.den) - ( nbr2.num * nbr.den);
  result.den = nbr.den * nbr2.den;
   
  nbr = result;
}
 
void multiply (Rational& nbr) {
  Rational nbr2;
  cin >> nbr2.num >> nbr2.den;
  Rational result;
  result.num = nbr.num * nbr2.num;
  result.den = nbr.den * nbr2.den;
 
  nbr = result;
}
 
void divide (Rational& nbr) {
  Rational nbr2;
  cin >> nbr2.num >> nbr2.den;
  Rational result;
  result.num = nbr.num * nbr2.den;
  result.den = nbr.den * nbr2.num;
 
  nbr = result;
}
 
 
 
void simplify(Rational& nbr) {
    Rational res;
  res.num=nbr.num/gcd(nbr.num,nbr.den);
  res.den=nbr.den/gcd(nbr.num,nbr.den);
  if (res.den<0) {
    res.den=res.den*(-1);
    res.num=res.num*(-1);
  }
  nbr=res;
}
 
void print(Rational& nbr) {
  if (nbr.num%nbr.den==0) cout<<nbr.num/nbr.den<<endl;
  else cout<<nbr.num<<"/"<<nbr.den<<endl;
}
 
   
int main() {
    Rational nbr;
    cin>>nbr.num>>nbr.den;
    simplify(nbr);
    print(nbr);
    string s;
    while (cin>>s) {
      if        (s=="add") add(nbr);
      else if   (s=="substract") substract(nbr);
      else if   (s=="multiply") multiply(nbr);
      else if   (s=="divide") divide(nbr);
      simplify(nbr);
      print(nbr);
    }
   
}