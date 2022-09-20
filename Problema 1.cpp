#include <iostream>
using namespace std;
int main(){
	int a[9][9];
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			if(i == j) a[i][j] = 0;
			else a[i][j] = (j+i)%8;

	//afisare
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++)
			cout << a[i][j] << " ";
		cout << "\n";
	}
	return 0;
}