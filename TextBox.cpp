#include "TextBox.h"

TextBox::~TextBox(){
}

TextBox::TextBox(string str, int x, int y, int width, int height) :CONTROL(str, x, y, width, height) {
	this->bc = Color::Blue;
	this->fc = Color::Orange;
	this->bt = BorderType::Single;
}

bool TextBox::canGetFocus(){
	return true;
}

// This function draw a control relatively to the control that holds it.
void TextBox::draw(Graphics graphics, int x_relative, int y_relative, size_t p){
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
	if (this->value.length() < this->_size.X - 2 || this->value.length() == this->_size.X - 2)
	{
		graphics.write(this->value);
	}
	this->showCursorOnScreen();

}

void TextBox::mousePressed(int x, int y, unsigned long button){

}

void TextBox::keyDown(unsigned short code, char ch){

	graphics.moveTo(this->_position.X + 2, this->_position.Y + 2);
	this->value = this->value + string(1, ch);
	graphics.write(this->value);
	COORD coord;
	coord.Y = CONTROL::getFocus()->getCursor().Y;
	switch (code){
	case VK_BACK:

		break;
	case VK_RIGHT:
	case VK_NUMPAD6:
		coord.X = CONTROL::getFocus()->getCursor().X + 1;
		CONTROL::setCursor(coord);
		break;
	case VK_LEFT:
	case VK_NUMPAD4:
		coord.X = CONTROL::getFocus()->getCursor().X - 1;
		CONTROL::setCursor(coord);
		break;
	case VK_RETURN:
		break;
	case VK_DELETE:
		break;
	default:
		if ((code >= 65 && code <= 90) || (code >= 97 && code <= 122) || (code >= 48 && code <= 57) || (code == 32))

			break;
	}


}