#pragma once

#include "CONTROL.h"
#include "MouseListener.h"

class Button : public CONTROL {
private:
	MouseListener *_listener;
protected:
public:
	Button(string, int, int, int, int);
	virtual ~Button();
	void draw(Graphics, int, int, size_t);
	void mousePressed(int, int, unsigned long);
	void keyDown(unsigned short, char);
	bool canGetFocus();

	void AddListener(MouseListener&);

};