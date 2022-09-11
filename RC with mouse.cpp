#include <iostream>
#include <windows.h>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;
#include "mousecon.h"

DWORD extra;
int dist = 10;

HANDLE ho = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hi = GetStdHandle(STD_INPUT_HANDLE);

int buffer[80][80];
int prevbuffer[80][80];
string printbuffer;

void DrawBoundary(double x1, double y1, int x2, int y2){
	int vx = x2 - x1;
	int vy = y2 - y1;
	int step = max(abs(vx), abs(vy));
	double xinc = (double)vx/step;
	double yinc = (double)vy/step;
	while(step >= 0){
		buffer[(int)round(x1)][(int)round(y1)] = 1;
		x1 += xinc;
		y1 += yinc;
		step--;
	}
}

void DrawRay(double x1, double y1, int x2, int y2){
	int vx = x2 - x1;
	int vy = y2 - y1;
	int step = max(abs(vx), abs(vy));
	double xinc = (double)vx/step;
	double yinc = (double)vy/step;
	while(buffer[(int)round(x1)][(int)round(y1)] != 1){
		// if(prevbuffer[(int)round(x1)][(int)round(y1)] != buffer[(int)round(x1)][(int)round(y1)]){
		// 	if(buffer[(int)round(x1)][(int)round(y1)] == 0){

		// 	}
		// }
		buffer[(int)round(x1)][(int)round(y1)] = 3;
		x1 += xinc;
		y1 += yinc;
		step--;
	}
}

int main(int argc, char ** argv){
	system("cls");
	SetConsoleMode(hi, ENABLE_MOUSE_INPUT);
	stringstream ss;
	if(argc >= 1){
		ss << argv[1];
		ss >> dist;
	}
	for(int i=0;i<80;i++){
		buffer[i][0] = 1;
		buffer[i][79] = 1;
		buffer[0][i] = 1;
		buffer[79][i] = 1;
	}

	DrawBoundary(10, 10, 10, 15);
	DrawBoundary(10, 20, 10, 25);
	DrawBoundary(10, 30, 10, 35);
	DrawBoundary(10, 40, 10, 45);
	DrawBoundary(10, 50, 10, 55);
	DrawBoundary(10, 60, 10, 65);

	DrawBoundary(50, 30, 70, 30);
	DrawBoundary(70, 30, 70, 60);
	DrawBoundary(70, 60, 50, 60);
	DrawBoundary(50, 60, 50, 30);

	DrawBoundary(30, 50, 35, 50);
	DrawBoundary(35, 50, 35, 55);
	DrawBoundary(35, 55, 30, 55);
	DrawBoundary(30, 55, 30, 50);

	DrawBoundary(25, 15, 75,  5);

	while(!GetAsyncKeyState('\e')){
		COORD coord = GetMouseCoord(hi);
		if(coord.X && coord.Y){
			for(int i=coord.X-dist;i<coord.X+dist+1;i++){
				DrawRay(coord.X, coord.Y, i, coord.Y-dist);
			}
			for(int i=coord.Y-dist;i<coord.Y+dist+1;i++){
				DrawRay(coord.X, coord.Y, coord.X+dist, i);
			}
			for(int i=coord.X+dist;i>coord.X-dist-1;i--){
				DrawRay(coord.X, coord.Y, i, coord.Y+dist);
			}
			for(int i=coord.Y+dist;i>coord.Y-dist-1;i--){
				DrawRay(coord.X, coord.Y, coord.X-dist, i);
			}
			for(int i=0;i<80;i++){
				for(int j=0;j<80;j++){
					if(buffer[i][j] == 3) buffer[i][j] = 2;
					else if(buffer[i][j] == 2) buffer[i][j] = 0;
				}
			}
			for(int i=0;i<80;i++){
				for(int j=0;j<80;j++){
					if(buffer[i][j] != prevbuffer[i][j]){
						if(buffer[i][j] == 0){
							WriteConsoleOutputCharacter(ho, " ", 1, {i, j}, &extra);
						}
						else if(buffer[i][j] == 1){
							WriteConsoleOutputCharacter(ho, "#", 1, {i, j}, &extra);
						}
						else if(buffer[i][j] == 2){
							WriteConsoleOutputCharacter(ho, ".", 1, {i, j}, &extra);
						}
					}
					prevbuffer[i][j] = buffer[i][j];
				}
			}
		}
	}
	system("cls");
	return 0;
}
