#include <iostream>
#include <cstring>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
HANDLE ho = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hi = GetStdHandle(STD_INPUT_HANDLE);
DWORD nrEvents = 0;
DWORD nrEventsRead = 0;
CONSOLE_CURSOR_INFO cursor;
char ch;
int main(){
	ch = getch();
	GetConsoleCursorInfo(ho, &cursor);
	cursor.bVisible = false;
	SetConsoleCursorInfo(ho, &cursor);
	system("cls");
	SetConsoleMode(hi, ENABLE_MOUSE_INPUT);
	while(1){
		GetNumberOfConsoleInputEvents(hi, &nrEvents);
		if(nrEvents){
			INPUT_RECORD eventBuffer[nrEvents];
			ReadConsoleInput(hi, eventBuffer, nrEvents, &nrEventsRead);
			for(int i=0;i<nrEventsRead;i++){
				SetConsoleTextAttribute(ho, rand()%16);
				if(eventBuffer[i].EventType == MOUSE_EVENT){
					if(eventBuffer[i].Event.MouseEvent.dwButtonState == 1){
						SetConsoleCursorPosition(ho, {eventBuffer[i].Event.MouseEvent.dwMousePosition.X,eventBuffer[i].Event.MouseEvent.dwMousePosition.Y});
						cout << ch;
					}
				}
			}
		}
	}
	return 0;
}