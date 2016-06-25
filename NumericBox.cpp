#include "NumericBox.h"

/*NumericBox::NumericBox(int width, int min, int max): Control(width), _min(min), _max(max) {

}*/

NumericBox::NumericBox(int min, int max, string str, int x, int y, int width, int height) : Panel(str, x, y, width, height), _min(min), _max(max) {
	Button minusBtn = Button("-", x + width, y, 1, 1);
	Button plusBtn = Button("+", x + width, y+1, 1, 1);

	Minus minListener = Minus(*this);
	Plus plusListener = Plus(*this);

	minusBtn.AddListener(minListener);
	plusBtn.AddListener(plusListener);

	this->AddControl(minusBtn);
	this->AddControl(plusBtn);
}

NumericBox::~NumericBox() {

}

bool NumericBox::canGetFocus() {
	return true;
}

void NumericBox::draw(Graphics graphics, int x_relative, int y_relative, size_t p) {
	//set graphics
	this->graphics = graphics;
	graphics.setBackground(bc);
	graphics.setForeground(fc);
	// change color of textbox in focus
	if (this == focus)
	{
		graphics.setBackground(Color::White);
		graphics.setForeground(Color::Black);
	}
	// init position
	int xAbs = this->_position.X + x_relative,
		yAbs = this->_position.Y + y_relative;
	// draw frame of control
	drawFrame(graphics, xAbs, yAbs);
	// init position
	graphics.moveTo(xAbs + 1, yAbs + 1);
	// draw control content
	graphics.write(this->value);
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

NumericBox::Plus::Plus(CONTROL& c) : _c(c) {

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

NumericBox::Minus::Minus(CONTROL& c) : _c(c) {

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