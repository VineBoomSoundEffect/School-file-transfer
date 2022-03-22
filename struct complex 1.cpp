//2 numere complexe
//suma lor
//produsul lor
//modulul fiecaror
//conjugatul fiecaror
#include <iostream>
#include <cmath>
using namespace std;
struct complex{
	float re, im;
}x, y, s, p;
float mx, my;
int main(){
	cout << "Introdu x:\npartea reala: "; cin >> x.re;
	cout << "partea imaginara: "; cin >> x.im;
	cout << "Introdu y:\npartea reala: "; cin >> y.re;
	cout << "partea imaginara: "; cin >> y.im;
	s.re = x.re + y.re;
	s.im= x.im + y.im;
	cout << "Suma numerelor este: " << s.re << " + " << s.im << "i\n";
	p.re = (x.re*y.re) + (x.im*y.im*(-1));
	p.im = (x.re*y.im) + (y.re*x.im);
	cout << "Produsul numerelor este: " << p.re << " + " << p.im << "i\n";
	mx = sqrt(pow(x.re, 2) + pow(x.im, 2));
	my = sqrt(pow(y.re, 2) + pow(y.im, 2));
	cout << "Modulul lui x este: " << mx << "\n";
	cout << "Modulul lui y este: " << my << "\n";
	if(x.im > 0) cout << "Conjugatul lui x este: " << x.re << " - " << x.im << "i\n";
	else cout << "Conjugatul lui x este: " << x.re << " + " << x.im << "i\n";
	if(y.im > 0) cout << "Conjugatul lui y este: " << y.re << " - " << y.im << "i\n";
	else cout << "Conjugatul lui y este: " << y.re << " + " << y.im << "i\n";
	return 0;
}
