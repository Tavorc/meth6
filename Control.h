//Component.h

#ifndef __COMPONENT_H_INCLUDED__   // if x.h hasn't been included yet...
#define __COMPONENT_H_INCLUDED__   //   #define this so the compiler knows it has been included

#include <windows.h>
#include <iostream>
using namespace std;

enum class BorderType { Single, Double, None};
enum class Color { Red, Blue, Green, Purple, Teal, Yellow, White, Black, Orange, Cyan };

class CONTROL{

private:
	
protected:
	HANDLE _console;
	COORD _size;
	COORD _width;
	Color _background;
	Color _foreground;
	void updateConsoleAttributes();
	static  CONTROL * CONTROL::SOMETHING;
	
public:
	virtual void Show();// = 0;
	virtual void Hide();
	void SetSize(COORD);
	void SetLocation(COORD);
	static CONTROL* GetFocus();
	static void setFocus(CONTROL& ct);
	CONTROL(){};
	virtual void CONTROL::Handle(INPUT_RECORD *inpt) = 0;
	CONTROL(HANDLE _console, COORD size);

	void CONTROL::MoveTo(int x, int y);
};

#endif a