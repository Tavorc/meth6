#pragma once

#include "CONTROL.h"
#include <vector>

class Panel : public CONTROL
{
private:
protected:
	vector<CONTROL*> controls;
public:
	Panel(string, int, int, int, int);
	virtual ~Panel();
	void AddControl(CONTROL&);
	virtual void draw(Graphics, int, int, size_t);
	void mousePressed(int, int, unsigned long);
	void keyDown(unsigned short, char);
	void incrementZIndex(CONTROL & control);
	
private:
};