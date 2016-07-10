#include "NumericBox.h"

NumericBox::NumericBox(int width, int min, int max): Panel(1, width+2), _min(min), _max(max) ,_label(width) {
//NumericBox::NumericBox(int width, int min, int max) : Control(width), _min(min), _max(max) {

	addControl(_label, 0, 0);

	/*Button minusBtn = Button(1);
	minusBtn.setText("-");
	Button plusBtn = Button(1);
	plusBtn.setText("+");

	Minus minListener(*this);
	Plus plusListener(*this);

	minusBtn.addListener(minListener);
	plusBtn.addListener(plusListener);

	this->addControl(minusBtn, width, 1);
	this->addControl(plusBtn, width, 3);*/
}

NumericBox::~NumericBox() {

}

void NumericBox::setValue(int value) {
	_label.setText(to_string(value));
}

bool NumericBox::canGetFocus() {
	return true;
}

void NumericBox::draw(Graphics graphics, int x, int y, size_t layer) {
	_label.setPosition({ x, y });
	Panel::draw(graphics, x, y, layer);
}

void NumericBox::mousePressed(int x, int y, bool isLeft){

}

void NumericBox::keyDown(int code, char ch){
	int value = stoi(getText());
	if (code == VK_DOWN) {
		if (value - 1 >= _min) value -= 1;
	}
	else if (code == VK_UP) {

	}
	setValue(value);
	//graphics.write(value);
}

/*NumericBox::Plus::Plus(Control& c) : _c(c) {

}

void NumericBox::Plus::mousePressed(Control& c, int x, int y, bool isLeft) {
	NumericBox nb = (NumericBox&)c;
	int value = stoi(nb.getText());
	if (isLeft) {
		if (value + 1 <= nb._max) value += 1;
		nb.setValue(value);
		//nb.graphics.write(value);
	}
}

NumericBox::Minus::Minus(Control& c) : _c(c) {

}

void NumericBox::Minus::mousePressed(Control& c, int x, int y, bool isLeft) {
	NumericBox nb = (NumericBox&)c;
	int value = stoi(nb.getText());
	if (isLeft) {
		if (value - 1 >= nb._min) value -= 1;
		nb.setValue(value);
		//nb.graphics.write(value);
	}
}*/