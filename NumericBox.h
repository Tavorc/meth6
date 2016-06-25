#pragma once

#include "Panel.h"
#include "MouseListener.h"
#include "Button.h"

class NumericBox : public Panel {
private:
	int _min;
	int _max;

	struct Plus : public MouseListener {
	private:
		CONTROL& _c;
	public:
		Plus(CONTROL&);
		void MousePressed(CONTROL&, int, int, bool);
	};

	struct Minus : public MouseListener {
	private:
		CONTROL& _c;
	public:
		Minus(CONTROL&);
		void MousePressed(CONTROL&, int, int, bool);
	};
	
protected:
public:
	//NumericBox(int, int, int);
	NumericBox(int, int, string, int, int, int, int);
	virtual ~NumericBox();
	void draw(Graphics, int, int, size_t);
	void mousePressed(int, int, unsigned long);
	void keyDown(unsigned short, char);
	bool canGetFocus();

};