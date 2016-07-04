#pragma once

#include "../Control/Control.h"

class TextBox : public Control {
private:

protected:

public:
	TextBox(int);
	~TextBox();

	virtual void draw(Graphics&, int, int, size_t);
	virtual void mousePressed(int, int, bool);
	virtual void keyDown(int, char);
	virtual bool canGetFocus() const;
	void Clear();

};