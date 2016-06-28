#pragma once

#include "CONTROL.h"
#include <vector>

class TextBox : public CONTROL
{

private:
	bool flag;
	COORD cursor;
protected:
public:
	TextBox(string, int, int, int, int);
	virtual ~TextBox();
	void draw(Graphics, int, int, size_t);
	void mousePressed(int, int, unsigned long);
	void keyDown(unsigned short, char);
	bool canGetFocus();
	bool PutChar(char ch);
	void PrintChar(char ch);
	void MoveLeft();
	void MoveRight();
	void BackSpace();
	void Clear();
	void Delete();
	void SetCursor(int x, int y);
	
	
	
private:
};