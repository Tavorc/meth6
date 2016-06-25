#include "Button.h"

Button::Button(string str, int x, int y, int width, int height) : CONTROL(str, x, y, width, height) {

}

Button::~Button() {

}

bool Button::canGetFocus() {
	return false;
}

void Button::draw(Graphics graphics, int x_relative, int y_relative, size_t p) {
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

void Button::AddListener(MouseListener& listener) {
	_listener = &listener;
}

void Button::mousePressed(int x, int y, unsigned long ch) {
	if (ch == FROM_LEFT_1ST_BUTTON_PRESSED) _listener->MousePressed(*this, x, y, true);
	else _listener->MousePressed(*this, x, y, false);
}

void Button::keyDown(unsigned short code, char ch){

}