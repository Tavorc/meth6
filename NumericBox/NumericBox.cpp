#include "NumericBox.h"

NumericBox::NumericBox(int width, int min, int max): Panel(1, width+2), _min(min), _max(max) ,_label(width), _minusBtn(1), _plusBtn(1) {
	addControl(_label, 0, 0);

	_minusBtn.setText("-");
	_plusBtn.setText("+");

	Minus* minListener = new Minus(*this);
	Plus* plusListener = new Plus(*this);

	_minusBtn.addListener(*minListener);
	_plusBtn.addListener(*plusListener);

	addControl(_minusBtn, width, 1);
	addControl(_plusBtn, width, 3);
}

NumericBox::~NumericBox() {

}

void NumericBox::setValue(int value) {
	if (value >= _min && value <= _max) {
		_label.setText(to_string(value));
		setText(to_string(value));
	}	
}

bool NumericBox::canGetFocus() const {
	return false;
}

void NumericBox::draw(Graphics& graphics, int x, int y, size_t layer) {
	_minusBtn.setBorderosition(getBorder());
	_plusBtn.setBorderosition(getBorder());
	if (getBorder() != BorderType::None) {
		_label.setPosition({ GetLeft() + 1, getTop() + 1 });
		_plusBtn.setPosition({ GetLeft() + getWidth() + 2, getTop() + getHeight() -1 });
		_minusBtn.setPosition({ GetLeft() + getWidth() + 5, getTop() + getHeight() -1 });
	} else {
		_label.setPosition({ GetLeft(), getTop() });
		_plusBtn.setPosition({ GetLeft() + getWidth() + 2, getTop() });
		_minusBtn.setPosition({ GetLeft() + getWidth() + 5, getTop() });
	}
	Control::draw(graphics, x, y, layer);
	Panel::draw(graphics, x, y, layer + 1);
}

void NumericBox::mousePressed(int x, int y, bool isLeft){

}

void NumericBox::keyDown(int code, char ch){
	int value = stoi(getText());
	if (code == VK_DOWN) value -= 1;
	else if (code == VK_UP) value += 1;
	setValue(value);
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