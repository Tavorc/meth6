#pragma once

#include "Control.h"

class ComboBox : public CONTROL {
private:

public:
	ComboBox(string, int, int, int, int);
	virtual ~ComboBox();
	void draw(Graphics, int, int, size_t);
	void mousePressed(int, int, unsigned long);
	void keyDown(unsigned short, char);
	bool canGetFocus();
};