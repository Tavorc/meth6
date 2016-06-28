#include "NumericBox.h"

/*NumericBox::NumericBox(int width, int min, int max): Control(width), _min(min), _max(max) {

}*/

NumericBox::NumericBox(string str, int x, int y, int width, int height, int min, int max) : Panel(str, x, y, width, height), _min(min), _max(max) {
	CONTROL *  minusBtn = new  Button("-", this->getWidth(), 0, 3, 3);
	CONTROL *  plusBtn = new Button("+", -3, 0, 3, 3);
	AddControl(*minusBtn);
	AddControl(*plusBtn);
}

NumericBox::Minus::Minus(CONTROL& c) : _c(c) {

}

NumericBox::Plus::Plus(CONTROL& c) : _c(c) {

}

NumericBox::~NumericBox() {

}

bool NumericBox::canGetFocus() {
	return true;
}

void NumericBox::mousePressed(int x, int y, unsigned long button){

}

void NumericBox::keyDown(unsigned short code, char ch){
	int value = stoi(this->value);
	if (code == VK_DOWN) {
		if (value - 1 >= _min) value -= 1;
	}
	else if (code == VK_UP) {
	}
	this->value = to_string(value);
	graphics.write(this->value);
}

void NumericBox::Plus::MousePressed(CONTROL& c, int x, int y, bool isLeft) {
	NumericBox nb = (NumericBox&)c;
	int value = stoi(nb.value);
	if (isLeft) {
		if (value + 1 <= nb._max) value += 1;
		nb.value = to_string(value);
		nb.graphics.write(nb.value);
	}
}

void NumericBox::Minus::MousePressed(CONTROL& c, int x, int y, bool isLeft) {
	NumericBox nb = (NumericBox&)c;
	int value = stoi(nb.value);
	if (isLeft) {
		if (value - 1 >= nb._min) value -= 1;
		nb.value = to_string(value);
		nb.graphics.write(nb.value);
	}
}