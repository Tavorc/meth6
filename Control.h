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
	BorderType _frame;
	Color _background;
	Color _foreground;
	COORD _size;
	void updateConsoleAttributes();
	static  CONTROL * CONTROL::SOMETHING;
	
public:
	
	virtual	void MoveTo(int, int);// = 0;
	virtual void Show();// = 0;
	virtual void Hide();
	
	void SetForegroundColor(Color);
	void SetBackgroundColor(Color);
	void SetBorder(BorderType);
	void SetSize(COORD);
	void SetLocation(COORD);
	static CONTROL* GetFocus();
	static void setFocus(CONTROL& ct);
	CONTROL(){};
	virtual void CONTROL::Handle(INPUT_RECORD *inpt) = 0;
	CONTROL(HANDLE _console, BorderType frame, Color bc, Color fc, COORD size);
};

#endif a