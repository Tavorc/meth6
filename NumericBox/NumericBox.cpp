#include "NumericBox.h"

NumericBox::NumericBox(int width, int min, int max) : Panel(1, width + 2), _min(min), _max(max), _label(width), _minusBtn(1), _plusBtn(1) {

	_minusBtn.setText("-");
	_plusBtn.setText("+");

	// create listeners for '+' & '-' buttons
	Minus* minListener = new Minus(*this);
	Plus* plusListener = new Plus(*this);

	_minusBtn.addListener(*minListener);
	_plusBtn.addListener(*plusListener);

	// add label & buttons to numericBox which inherits from panel
	addControl(_label, 0, 0);
	addControl(_minusBtn, width, 1);
	addControl(_plusBtn, width, 3);
}

NumericBox::~NumericBox() {

}

void NumericBox::setValue(int value) {
	// validate before assigning new value
	if (value >= _min && value <= _max) {
		_label.setText(to_string(value));
		setText(to_string(value));
	}
}

void NumericBox::setMin(int min) {
	_min = min;
}

void NumericBox::setMax(int max) {
	_max = max;
}

int NumericBox::getValue() const {
	return stoi(_label.getText());
}

bool NumericBox::canGetFocus() const {
	return false;
}

void NumericBox::draw(Graphics& graphics, int x, int y, size_t layer) {
	// border type of buttons is the same as label
	_minusBtn.setBorderosition(getBorder());
	_plusBtn.setBorderosition(getBorder());
	if (getBorder() != BorderType::None) {
		_label.setPosition({ GetLeft() + 4, getTop() + 1 });
		_plusBtn.setPosition({ GetLeft() + getWidth() + 5, getTop() + getHeight() - 1 });
		_minusBtn.setPosition({ GetLeft(), getTop() + getHeight() - 1 });

	}
	else {
		_label.setPosition({ GetLeft() + 4, getTop() });
		_plusBtn.setPosition({ GetLeft() + getWidth() + 5, getTop() });
		_minusBtn.setPosition({ GetLeft(), getTop() });
	}
	Control::draw(graphics, x + 3, y, layer);
	Panel::draw(graphics, x, y, layer + 1);
}

void NumericBox::mousePressed(int x, int y, bool isLeft){

}

void NumericBox::keyDown(int code, char ch){

}

NumericBox::Plus::Plus(Control& c) : _c(c) {

}

void NumericBox::Plus::mousePressed(Control& c, int x, int y, bool isLeft) {
	if (c.isClicked(x, y)) {
		NumericBox& nb = static_cast<NumericBox&>(_c);
		int value = stoi(nb.getText());
		nb.setValue(value + 1);
	}
}

NumericBox::Minus::Minus(Control& c) : _c(c) {

}

void NumericBox::Minus::mousePressed(Control& c, int x, int y, bool isLeft) {
	if (c.isClicked(x, y)) {
		NumericBox& nb = static_cast<NumericBox&>(_c);
		int value = stoi(nb.getText());
		nb.setValue(value - 1);
	}
}