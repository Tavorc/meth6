#include "Control.h"

CONTROL::CONTROL(HANDLE console, HANDLE hstdin, BorderType frame, Color bc, Color fc, COORD size, COORD location){
	this->_frame = frame;
	this->_background = bc;
	this->_foreground = fc;
	this->_size = size;
	this->_location = location;
	this->_console = console;
	this->_hstdin = hstdin;
	updateConsoleAttributes();
}


CONTROL& CONTROL::GetFocus(){
	this->SOMETHING = NULL;
	return *(CONTROL::SOMETHING);
}

void  CONTROL::Show(){
}
void  CONTROL::Hide(){
}

/*
void CONTROL::SetFocus(int _control){
	CONTROL::a = _control;
}
*/
void CONTROL::SetForegroundColor(Color fc)
{
	this->_foreground = fc;
}
void CONTROL::SetBackgroundColor(Color bc){
	this->_background = bc;
}
void CONTROL::SetBorder(BorderType frame){
	this->_frame = frame;
}
void CONTROL::MoveTo(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(_console, c);
}
void CONTROL:: SetSize(COORD sz){
	this->_size = sz;
}
void CONTROL::SetLocation(COORD loc){
	this->_location = loc;
}
void CONTROL::updateConsoleAttributes()
{
	DWORD attributes = 0;

	switch (_foreground)
	{
	case Color::Black:	break;
	case Color::Blue:	attributes |= FOREGROUND_BLUE; break;
	case Color::Green:	attributes |= FOREGROUND_GREEN; break;
	case Color::Red:	attributes |= FOREGROUND_RED; break;
	case Color::Cyan:	attributes |= FOREGROUND_BLUE | FOREGROUND_GREEN; break;
	case Color::Purple:	attributes |= FOREGROUND_BLUE | FOREGROUND_RED; break;
	case Color::Orange: attributes |= FOREGROUND_GREEN | FOREGROUND_RED; break;
	case Color::White:	attributes |= FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED; break;
	}

	switch (_background)
	{
	case Color::Black:	break;
	case Color::Blue:	attributes |= BACKGROUND_BLUE; break;
	case Color::Green:	attributes |= BACKGROUND_GREEN; break;
	case Color::Red:	attributes |= BACKGROUND_RED; break;
	case Color::Cyan:	attributes |= BACKGROUND_BLUE | BACKGROUND_GREEN; break;
	case Color::Purple:	attributes |= BACKGROUND_BLUE | BACKGROUND_RED; break;
	case Color::Orange: attributes |= BACKGROUND_GREEN | BACKGROUND_RED; break;
	case Color::White:	attributes |= BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED; break;
	}

	SetConsoleTextAttribute(_console, attributes);
}

// Handle and events
void CONTROL::Handle(INPUT_RECORD *inpt, int i){
	switch (inpt[i].EventType)
	{
	case KEY_EVENT: // keyboard input 
	{
						KEY_EVENT_RECORD ker = inpt[i].Event.KeyEvent;
						switch (ker.wVirtualKeyCode){
						case VK_BACK:
							break;
						case VK_TAB:
							if (inpt[i].Event.KeyEvent.bKeyDown){
							
							}
							break;
						case VK_RIGHT:
						case VK_NUMPAD6:
							break;
						case VK_LEFT:
						case VK_NUMPAD4:
							break;
						case VK_RETURN:
							break;
						case VK_DELETE:
							break;
						default:
							break;
						}
	}
	}
}