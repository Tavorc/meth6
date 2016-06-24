#pragma once

#include "Panel.h"
#include <vector>
using namespace System;
class Form : public Panel
{
private:
protected:
public:
	Form();
	virtual ~Form();
	void draw(Graphics, int, int, size_t);
	void mousePressed(int, int, unsigned long);
	void keyDown(unsigned short, char);
	bool canGetFocus();
private:
};