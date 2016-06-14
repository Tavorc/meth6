//Component.h

#ifndef __COMPONENT_H_INCLUDED__   // if x.h hasn't been included yet...
#define __COMPONENT_H_INCLUDED__   //   #define this so the compiler knows it has been included

#include <windows.h>

using namespace std;

enum class BorderType { Single, Double, None};
enum class Color { Red, Blue, Green, Purple, Teal, Yellow, White, Black, Orange, Cyan };


class CONTROL {
	static int a;
protected:
	HANDLE _console;
	HANDLE _hstdin;
	BorderType _frame;
	Color _background;
	Color _foreground;
	COORD _size;
	COORD _location;
	static CONTROL * CONTROL::SOMETHING;
	void updateConsoleAttributes();
public:
	
	virtual	void MoveTo(int, int) = 0;
	virtual void Show() = 0;
	virtual void Hide()= 0 ;
	
	virtual void SetForegroundColor(Color);
	virtual void SetBackgroundColor(Color);
	virtual void SetBorder(BorderType);
	virtual void SetSize(COORD);
	virtual void SetLocation(COORD);
	CONTROL& CONTROL::GetFocus();
	
//	CONTROL& CONTROL::GetFocus();
	//void CONTROL::SetFocus(CONTROL);
	void CONTROL::Handle(INPUT_RECORD *inpt, int i);
	CONTROL(){};
	CONTROL(HANDLE _console, HANDLE _hstdin, BorderType frame, Color bc, Color fc, COORD size, COORD location);
};

#endif a