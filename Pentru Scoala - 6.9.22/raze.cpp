#include <iostream>
#include <windows.h>
#include <cmath>
#include <conio.h>

#include <climits>

using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
COORD c = {40, 40};
DWORD a;
char ch;
int x = 40, y = 40;
long int counter = 2;
int ls[80][80];//logic screen
//if a cell is 1  -->  it is filled (boundary)
void Setpixel(int x, int y){
	//SetConsoleCursorPosition(h, {x, y});
	//cout << ".";
	ls[x][y] = counter;
	WriteConsoleOutputCharacter(h, ".", 1, {x, y}, &a); //faster than the two commented instructions above
}

void Setpixel1(int x, int y){
	ls[x][y] = 1;
	WriteConsoleOutputCharacter(h, "#", 1, {x, y}, &a);
}

void DDA_line(double x1, double y1, int x2, int y2){
	int vx = x2 - x1;
	int vy = y2 - y1;
	int step = max(abs(vx), abs(vy));
	double xinc = (double)vx/step;
	double yinc = (double)vy/step;
	while(ls[(int)round(x1)][(int)round(y1)] != 1){
		Setpixel(round(x1), round(y1));
		x1 += xinc;
		y1 += yinc;
		step--;
	}
}

void DDA_boundary(double x1, double y1, int x2, int y2){
	int vx = x2 - x1;
	int vy = y2 - y1;
	int step = max(abs(vx), abs(vy));
	double xinc = (double)vx/step;
	double yinc = (double)vy/step;
	while(step >= 0){
		Setpixel1(round(x1), round(y1));
		x1 += xinc;
		y1 += yinc;
		step--;
	}
}

void drawRay(int k){
	counter++;
	int i;
	for(i=c.X-k;i<c.X+k+1;i++){
		DDA_line(c.X, c.Y, i, c.Y-k);
	}
	for(i=c.Y-k;i<c.Y+k+1;i++){
		DDA_line(c.X, c.Y, c.X+k, i);
	}
	for(i=c.X+k;i>c.X-k-1;i--){
		DDA_line(c.X, c.Y, i, c.Y+k);
	}
	for(i=c.Y+k;i>c.Y-k-1;i--){
		DDA_line(c.X, c.Y, c.X-k, i);
	}
}

void Setboundary(int x, int y){
	ls[x][y] = 1;
	SetConsoleCursorPosition(h, {x, y});
	cout << "#";
}

void SetDefaultBoundary(){
	int i;
	SetConsoleTextAttribute(h, 12);
	for(i=0;i<80;i++){
		Setboundary(i, 0);
		Setboundary(0, i);
	}
	for(i=79;i>=0;i--){
		Setboundary(i, 79);
		Setboundary(79, i);
	}
	SetConsoleTextAttribute(h, 7);
}

void cls(){
	for(int i=1;i<79;i++)
	for(int j=1;j<79;j++)
		if(ls[i][j] == counter-1){
			WriteConsoleOutputCharacter(h, " ", 1, {i, j}, &a);
		}
}

void move(int k){
	while(1){
		ch = _getch();
		if(ch == 'w'){
			y--;
			c = {x, y};
			drawRay(k);
			cls();
		}
		else if(ch == 's'){
			y++;
			c = {x, y};
			drawRay(k);
			cls();
		}
		else if(ch == 'a'){
			x--;
			c = {x, y};
			drawRay(k);
			cls();
		}
		else if(ch == 'd'){
			x++;
			c = {x, y};
			drawRay(k);
			cls();
		}
	}
}
int main(){
	cout << "Welcome to my ray casting program!\n";
	cout << "Move around with WASD.\n";
	cout << "For good visuals, do the following:\n";
		cout << "   -right click the top window bar and select properties;\n";
		cout << "   -under Font, select Raster fonts, sized 8x8;\n";
		cout << "   -under Layout, under Window size, set the width and height to 80;\n";
	cout << "Press any key to continue.";
	_getch();
	system("cls");
	SetDefaultBoundary();
	for(int i=20;i<40;i++){
		Setboundary(50, i);
	}
	DDA_boundary(7, 13, 18, 30);
	DDA_boundary(8, 13, 19, 30);
	
	DDA_boundary(50, 50, 70, 50);
	DDA_boundary(70, 50, 70, 70);
	DDA_boundary(70, 70, 50, 70);
	DDA_boundary(50, 70, 50, 50);
	drawRay(10);
	move(10);
	return 0;
}
