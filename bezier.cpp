#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;
DWORD extra;
struct point{
    int y, x;
};
void bezier(int a[50][50], point p0, point p1, point p2){
    for(float t=0;t<1;t+=0.01){
        a[(int)round(pow(1-t, 2)*p0.x+2*t*(1-t)*p1.x+pow(t, 2)*p2.x)][(int)round(pow(1-t, 2)*p0.y+2*t*(1-t)*p1.y+pow(t, 2)*p2.y)] = 1;
    }
    a[p0.x][p0.y] = 2;
    a[p1.x][p1.y] = 2;
    a[p2.x][p2.y] = 2;
}
void output(int a[50][50]){
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            if(a[i][j] == 1) cout << "#";
            else if(a[i][j] == 2){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                cout << "@";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
            }
            else cout << ".";
        }
        cout << i << "\n";
    }
}
    int x[50][50];
int main(){
    bezier(x, {2, 2}, {40, 10},{40, 40});
    output(x);
    cout << "bezier curve";
    return 0;
}
