//APLICATIE CREATA DE TEODOR POMOHACI
//FARA RESTRICTII DE DISTRIBUTIE
#include <iostream>
#include <windows.h> //header-ul in care se afla majoritatea functiilor
#include <cstring>
using namespace std;
//header personalizat. eu l-am facut.
#include "mousecon.h"

//aceste 2 var. ajuta la manipularea liniei de comanda
HANDLE ho = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hi = GetStdHandle(STD_INPUT_HANDLE);

//variabile
DWORD extra;
char str[3]; //stocheaza ce anume se afiseaza pe ecran
int grid[80][50]; //matricea in care se desfasoara fizica
COORD coord; //coordonatele cursorului in relatie cu linia de comanda
int SAND  = 1; //constanta
int STONE = 2; //constanta
int CurrentType = SAND; //ce se genereaza cand dai click

int main(){
	//elibereaza ecranul
	system("cls");

	for(int i=19;i<60;i++){
		grid[i][30] = STONE;
	}

	//SETAREA "QUICK EDIT" TREBUIE DEZACTIVATA MANUAL
	SetConsoleMode(hi, ENABLE_MOUSE_INPUT);

	while(1){
		if(GetAsyncKeyState('1')) CurrentType = SAND;
		if(GetAsyncKeyState('2')) CurrentType = STONE;
		if(GetAsyncKeyState('3')) CurrentType = 0;
		if(GetAsyncKeyState('\e')){
			system("cls");
			return 0;
		}

		coord = GetMouseCoordWhenClicked(hi);
		if(CurrentType == 0)
			//functia WriteConsoleOutputCharacter() este mai eficienta decat cout, intrucat afiseaza caracterul dorit la coordonatele exacte fara a mai muta cursorul intern
			WriteConsoleOutputCharacter(ho, " ", 1, coord, &extra);
		grid[coord.X][coord.Y] = CurrentType;

		for(int j=50-1;j>0;j--){
			for(int i=0;i<80;i++){
				if(grid[i][j]==SAND && grid[i][j+1]==0 && j+1<50){
					int aux = grid[i][j+1];
					grid[i][j+1] = grid[i][j];
					grid[i][j] = aux;
					COORD tc = {i, j};
					WriteConsoleOutputCharacter(ho, " ", 1, tc, &extra);
				}
				if(grid[i][j]==SAND && grid[i+1][j+1] == 0 && grid[i][j+1]==SAND && j+1<50){
					int aux = grid[i+1][j+1];
					grid[i+1][j+1] = grid[i][j];
					grid[i][j] = aux;	
					COORD tc = {i, j};
					WriteConsoleOutputCharacter(ho, " ", 1, tc, &extra);
				}
				if(grid[i][j]==SAND && grid[i-1][j+1] == 0 && grid[i][j+1]==SAND && j+1<50){
					int aux = grid[i-1][j+1];
					grid[i-1][j+1] = grid[i][j];
					grid[i][j] = aux;
					COORD tc = {i, j};
					WriteConsoleOutputCharacter(ho, " ", 1, tc, &extra);
				}
			}
		}
		//bucla separata care afiseaza pe ecran
		for(int j=50-1;j>0;j--){
			for(int i=0;i<80;i++){
				if(grid[i][j] == SAND){
					COORD tc = {i, j};
					ReadConsoleOutputCharacter(ho, str, 1, tc, &extra);
					if(strcmp(str, ".")){
						WriteConsoleOutputCharacter(ho, ".", 1, tc, &extra);
					}
				}
				if(grid[i][j] == STONE){
					COORD tc = {i, j};
					ReadConsoleOutputCharacter(ho, str, 1, tc, &extra);
					if(strcmp(str, "#")){
						WriteConsoleOutputCharacter(ho, "#", 1, tc, &extra);
					}
				}
			}
		}
		Sleep(1);
	}
	return 0;
}