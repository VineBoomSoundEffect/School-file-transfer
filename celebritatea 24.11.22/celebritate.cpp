//celebritate: ge = 0, gi = n-1
//necunoscut:  ge = n-1, gi = 0
//singuratic: gs = 1
//strain: gs = 0

//a) ss precizeze celebritatea, daca nu exista, nodul cu ge min si nodul cu gi max
//b) ss precizeze necunoscutul, daca nu exista, nodul cu ge max si nodul cu ge min
//c) -||- singuraticii, daca exista
//d) -||- strainii, daca exista
//e) nodurile cu ge = 2 si gi = 3
//f) nodurile cu ge = gi
//g) nodurile cu arce duble intre ele

#include <iostream>
#include <fstream>
using namespace std;
void citire(int x[50][50], int &n, int &m, char fisier[255]){
	ifstream f(fisier);
	int i, j;
	f >> n >> m;
	for(int k=1;k<=m;k++){
		f >> i >> j;
		x[i][j] = 1;
	}
}
void afisare(int x[50][50], int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout << x[i][j] << " ";
		cout << "\n";
	}
}
void formareVector(int x[50][50], int n, int ve[50], int vi[50], int vs[50]){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			ve[i] += x[i][j];
			vi[i] += x[j][i];
			vs[i] = ve[i] + vi[i];
		}
}
int celebritate(int n, int ve[50], int vi[50]){
	for(int i=1;i<=n;i++)
		if(ve[i]==0 && vi[i]==n-1) return i;
	int min, max;
	min = n;
	max = 0;
	for(int i=1;i<=n;i++){
		if(min > ve[i]) min = i;
		if(max < vi[i]) max = i;
	}
	cout << "Persoana cunsoscuta de cele mai multe persoane este: " << max << "\n";
	cout << "Persoana care cunoaste cele mai putine persoane este: " << min << "\n";
	return 0;
}
int necunoscut(int n, int ve[50], int vi[50]){
	for(int i=1;i<=n;i++)
		if(ve[i]==n-1 && vi[i]==0) return i;
	int min, max;
	min = n;
	max = 0;
	for(int i=1;i<=n;i++){
		if(min > vi[i]) min = i;
		if(max < ve[i]) max = i;
	}
	cout << "Persoana cunsoscuta de cele mai putine persoane este: " << min << "\n";
	cout << "Persoana care cunoaste cele mai multe persoane este: " << max << "\n";
	return 0;
}
void singuratici(int n, int vs[50]){
	int ok = 0;
	for(int i=1;i<=n;i++)
		if(vs[i] == 1){
			ok++;
			if(ok == 1) //pentru ca mesajul sa se afiseze o singura data
				cout << "Singuraticii sunt: ";
			cout << i << " ";
		}
	if(ok == 0)
		cout << "Nu exista singuratici\n";
}
void straini(int n, int vs[50]){
	int ok = 0;
	for(int i=1;i<=n;i++)
		if(vs[i] == 0){
			ok++;
			if(ok == 1)
				cout << "Strainii sunt: ";
			cout << i << " ";
		}
	if(ok == 0)
		cout << "Nu exista straini\n";
}
void ge2gi3(int n, int ve[50], int vi[50]){
	int ok = 0;
	for(int i=1;i<=n;i++)
		if(ve[i]==2 && vi[i]==3){
			ok++;
			if(ok == 1)
				cout << "Asemenea persoane(ge2 gi3) sunt: ";
			cout << i << " ";
		}
	if(ok == 0)
		cout << "Nu exista asemenea persoane (ge2 gi3)\n";
}
void gradeEgale(int n, int ve[50], int vi[50]){
	int ok = 0;
	for(int i=1;i<=n;i++)
		if(ve[i]==vi[i]){
			ok++;
			if(ok == 1)
				cout << "Persoanele care cunosc atat cat sunt cunoscute sunt: ";
			cout << i << " ";
		}
	if(ok == 0)
		cout << "Nu exista persoane care cunosc atat cat sunt cunoscute\n";
}
void reciproc(int x[50][50], int n){
	int ok = 0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(x[i][j]==1 && x[j][i]==1){
				ok++;
				if(ok == 1)
					cout << "Persoanele care se cunsosc reciproc sunt:\n";
				cout << i << " " << j << "\n";
				j = n; //pentru a iesi din for
			}
	if(ok == 0)
		cout << "Nu exista persoane care se cunsosc reciproc\n";
}

int main(){
	int a[50][50], n, m, ve[50], vi[50], vs[50];
	citire(a, n, m, "date.txt");
	afisare(a, n);
	formareVector(a, n, ve, vi, vs);
	if(celebritate(n, ve, vi))
		cout << "Celebritatea este " << celebritate(n, ve, vi) << "\n";
	cout << "\n";
	if(necunoscut(n, ve, vi))
		cout << "Necunoscutul este " << necunoscut(n, ve, vi) << "\n";
	cout << "\n";
	singuratici(n, vs);
	cout << "\n";
	straini(n, vs);
	cout << "\n";
	ge2gi3(n, ve, vi);
	cout << "\n";
	gradeEgale(n, ve, vi);
	cout << "\n";
	reciproc(a, n);
	cout << "\n";
	return 0;
}
