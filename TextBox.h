#pragma once

#include "CONTROL.h"
#include <vector>

class TextBox : public CONTROL
{
private:
protected:
public:
	TextBox(string, int, int, int, int);
	virtual ~TextBox();
	void draw(Graphics, int, int, size_t);
	void mousePressed(int, int, unsigned long);
	void keyDown(unsigned short, char);
	bool canGetFocus();
private:
};