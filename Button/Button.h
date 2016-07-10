#pragma once

#include "../Control/Control.h"

struct MouseListener
{
	virtual void mousePressed(Control &control, int x, int y, bool isLeft) = 0;
};

class Button : public Control {

private:
	vector<MouseListener*> listeners;
public:
	Button(int width);
	virtual ~Button();
	void draw(Graphics&, int, int, size_t);
	void mousePressed(int, int, bool);
	void keyDown(int, char);
	bool canGetFocus() const;
	void addListener(MouseListener &listener);
};