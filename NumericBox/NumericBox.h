#pragma once

#include "../Panel/Panel.h"
#include "../Label/Label.h"
#include "../Button/Button.h"

class NumericBox : public Panel {
private:
	int _min;
	int _max;
	Label _label;
	Button _minusBtn;
	Button _plusBtn;

	struct Plus : public MouseListener {
	private:
		Control& _c;
	public:
		Plus(Control& c);
		void mousePressed(Control&, int, int, bool);
	};

	struct Minus : public MouseListener {
	private:
		Control& _c;
	public:
		Minus(Control&);
		void mousePressed(Control&, int, int, bool);
	};

protected:
public:
	NumericBox(int, int, int);
	virtual ~NumericBox();

	void setValue(int);
	void setMin(int);
	void setMax(int);

	int getValue() const;
	
	virtual void draw(Graphics&, int, int, size_t);
	void mousePressed(int, int, bool);
	void keyDown(int, char);
	bool canGetFocus() const;

};