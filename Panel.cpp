#include "Panel.h"

Panel::~Panel(){
}

Panel::Panel(string str, int x, int y, int width, int height) :CONTROL(str, x, y, width, height) {
}

// Draws a control relatively to the control that holds it.
void Panel::draw(Graphics graphics, int x_relative, int y_relative, size_t p){
	// Draw the Panel
	if (p == this->getZIndex())
	{
		//set graphics
		this->graphics = graphics;
		// set colors
		graphics.setBackground(bc);
		graphics.setForeground(fc);
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
	// Draw panels children
	for (CONTROL *c : this->controlsList) {
		if (p == c->getZIndex() && c != this)
		{
			// set colors
			c->setGraphics();
			// init position
			int xAbs = c->getLeft() + x_relative,
				yAbs = c->getTop() + y_relative;
			// draw frame of control
			c->draw(graphics, 0, 0,p);
			// init position
			graphics.moveTo(xAbs + 1, yAbs + 1);
			// draw control content
			graphics.write(c->getValue());
		}
	}
	
}

// Adds control to the panel
void Panel::AddControl(CONTROL& c){
	controls.push_back(&c);
	c.SetParent(*this);
	c.setPosition(this->getLeft() + c.getLeft(), this->getTop() + c.getTop());
	((Panel&)c).setZIndex(this->getZIndex() + 1);
}

void Panel::mousePressed(int x, int y, unsigned long button){

}

void Panel::keyDown(unsigned short code, char ch){

}