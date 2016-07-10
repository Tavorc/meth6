#pragma once

#include "../Control/Control.h"

class Label : public Control {
private:

protected:

public:
	Label(int);
	~Label();

	virtual void draw(Graphics&, int, int, size_t);
	virtual void mousePressed(int, int, bool);
	virtual void keyDown(int, char);
	virtual bool canGetFocus() const;
};