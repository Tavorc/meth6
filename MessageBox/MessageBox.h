#pragma once

#include "../Panel/Panel.h"
#include "../Label/Label.h"
#include "../Button/Button.h"


struct CancelListener : public MouseListener {
private:
	Control& _c;
public:
	CancelListener(Control &c) : _c(c) { }
	void mousePressed(Control  &b, int x, int y, bool isLeft)
	{
		_c.setVisibility(false);
		_c.setText("Cancel");
		Control::setFocus(&_c);
	}
};

struct OkListener : public MouseListener {
private:
	Control& _c;
public:
	OkListener(Control &c) : _c(c) { }
	void mousePressed(Control  &b, int x, int y, bool isLeft)
	{
		_c.setVisibility(false);
		_c.setText("Ok");
		Control::setFocus(&_c);
	}
};

class MessageB : public Panel {
private:

	Label _title;
	Label _text;
	Button _cancele;
	Button _accept;
	OkListener  _acceptListener;
	CancelListener  _cancelListener;

protected:
public:
	MessageB(int,int);
	virtual ~MessageB();

	virtual void setLayer(size_t layer);
	virtual void setTitle(string title);
	virtual void setText(string text);
	virtual void draw(Graphics&, int, int, size_t);
	virtual void mousePressed(int, int, bool);
	virtual void keyDown(int, char);
	bool canGetFocus();

};