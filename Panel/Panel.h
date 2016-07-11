#pragma once

#include "../Control/Control.h"

class Panel : public Control {
private:

	vector<Control*> _controls;

protected:

public:
	Panel();
	Panel(int, int);
	~Panel();

	virtual void addControl(Control &, int, int);

	virtual void getAllControls(vector<Control*>&);
	virtual void draw(Graphics&, int, int, size_t);
	virtual void mousePressed(int, int, bool);
	virtual void keyDown(int, char);

	virtual bool canGetFocus() const;
	virtual void setVisibility(bool);
	virtual void setLayer(size_t);

	void setFocusByPosition(int x, int y);

};