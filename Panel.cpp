#include "Panel.h"

Panel::~Panel(){

}

Panel::Panel(string str, int x, int y, int width, int height) :CONTROL(str, x, y, width, height) {

}

// Draws a control relatively to the control that holds it.
void Panel::draw(Graphics graphics, int x_relative, int y_relative, size_t p){
	// Draw the Panel
	if (p == 1)
	{
		//set graphics
		this->graphics = graphics;
		// set colors
		this->setGraphics();
		// init position
		int xAbs = this->_position.X + x_relative,
			yAbs = this->_position.Y + y_relative;
		// draw frame of control
		drawFrame(graphics, xAbs, yAbs);
		// init position
		graphics.moveTo(xAbs + 1, yAbs + 1);
		// draw control content
		graphics.write(this->value);
		// Draw all controls
		for (CONTROL *c : this->controls) {
			c->draw(graphics, 0, 0, p);
		}
	}

	this->showCursorOnScreen();

}

// Adds control to the panel
void Panel::AddControl(CONTROL& c){
	controls.push_back(&c);
	c.setPosition(this->getLeft() + c.getLeft(), this->getTop() + c.getTop());
	c.SetParent(*this);
	c.setZIndex(1);
	// update cursor
	COORD cursor;
	cursor.X = c.getLeft() + c.getValue().length() + 1;
	cursor.Y = getTop() + 1;
	c.setCursor(cursor);
}

void Panel::mousePressed(int x, int y, unsigned long button){

}

void Panel::keyDown(unsigned short code, char ch){

}