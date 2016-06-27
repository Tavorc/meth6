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
	graphics.setCursorVisibility(true);
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

void TextBox::mousePressed(int x, int y, unsigned long button){

}

void TextBox::keyDown(unsigned short code, char ch){
	if (code == VK_LEFT)
		{
		//TODO
		//I have no idea how to move the cursor
		int x = this->_position.X + this->value.length() - 1;
		graphics.moveTo(x--, _position.Y);
		}
	if (code == VK_BACK)
	{
		//the same problem,I have no idea how to move the cursor
		int x = _position.X - value.length() - 1;
		graphics.moveTo(--x, 0);
		this->value[value.length() - 1] = '\0';
	
	}
	if (code == VK_RIGHT)
	{

	}
	
	if ((code >= 65 && code <= 90) || (code >= 97 && code <= 122) || (code >= 48 && code <= 57) || (code == 32))
	{
		this->value += ch;
	}
	
}




