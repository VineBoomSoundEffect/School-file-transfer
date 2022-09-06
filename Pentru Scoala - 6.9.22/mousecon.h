COORD GetMouseCoord(HANDLE h){
	//case of an error
	if(h == GetStdHandle(STD_OUTPUT_HANDLE)){
		cout << "Warning: Function GetMouseCoord() returns {0, 0}:\n";
		cout << "Maybe pass the input handle instead of output handle?\n";
		return {0, 0};
	}
	DWORD nrEvents = 0;
	DWORD nrEventsRead = 0;
	GetNumberOfConsoleInputEvents(h, &nrEvents);
	if(nrEvents){
		INPUT_RECORD EventBuffer[nrEvents];
		ReadConsoleInput(h, EventBuffer, nrEvents, &nrEventsRead);
		for(int i=0;i<nrEventsRead;i++){
			if(EventBuffer[i].EventType == MOUSE_EVENT){
				return {EventBuffer[i].Event.MouseEvent.dwMousePosition.X, EventBuffer[i].Event.MouseEvent.dwMousePosition.Y};
			}
		}
	}
}
COORD GetMouseCoordWhenClicked(HANDLE h){
	//case of an error
	if(h == GetStdHandle(STD_OUTPUT_HANDLE)){
		cout << "Warning: Function GetMouseCoordWhenClicked() returns {0, 0}:\n";
		cout << "Maybe pass the input handle instead of output handle?\n";
		return {0, 0};
	}
	DWORD nrEvents = 0;
	DWORD nrEventsRead = 0;
	GetNumberOfConsoleInputEvents(h, &nrEvents);
	if(nrEvents){
		INPUT_RECORD EventBuffer[nrEvents];
		ReadConsoleInput(h, EventBuffer, nrEvents, &nrEventsRead);
		for(int i=0;i<nrEventsRead;i++){
			if(EventBuffer[i].EventType == MOUSE_EVENT){
				if(EventBuffer[i].Event.MouseEvent.dwButtonState == 1){
					return {EventBuffer[i].Event.MouseEvent.dwMousePosition.X, EventBuffer[i].Event.MouseEvent.dwMousePosition.Y};
				}	
			}
		}
	}
}
bool IsKeyPressed(HANDLE h, char ch){
	//case of an error
	if(h == GetStdHandle(STD_OUTPUT_HANDLE)){
		cout << "Warning: Function IsKeyPressed() returns {0, 0}:\n";
		cout << "Maybe pass the input handle instead of output handle?\n";
		return 0;
	}
	DWORD nrEvents = 0;
	DWORD nrEventsRead = 0;
	GetNumberOfConsoleInputEvents(h, &nrEvents);
	if(nrEvents){
		INPUT_RECORD EventBuffer[nrEvents];
		ReadConsoleInput(h, EventBuffer, nrEvents, &nrEventsRead);
		for(int i=0;i<nrEventsRead;i++){
			if(EventBuffer[i].EventType == KEY_EVENT){
				if(EventBuffer[i].Event.KeyEvent.wVirtualKeyCode == ch){
					return 1;
				}
			}
		}
	}
	return 0;
}