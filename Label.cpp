#include "Label.h"

LABEL::LABEL(){
	_console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci = { 10, TRUE };
	SetConsoleCursorInfo(_console, &cci);
	//set foreground color
	DWORD wAttr = 0;
	SetConsoleTextAttribute(_console, wAttr);
	CONSOLE_SCREEN_BUFFER_INFO cbi;
	GetConsoleScreenBufferInfo(_console, &cbi);
	DWORD wAttr2 = cbi.wAttributes | FOREGROUND_GREEN;
	SetConsoleTextAttribute(_console, wAttr2);
}
void LABEL::MoveTo(int, int){
}
void LABEL::Show(){
	cout << "ss";
}
void LABEL::Hide(){
}
void LABEL::Handle(INPUT_RECORD *inpt){

	//set cursor size and visibility example

	cout << " s";
}