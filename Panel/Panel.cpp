#include "Panel.h"

Panel::Panel() : Control(0), _height(0) {

}

Panel::Panel(int height, int width) : Control(width), _height(height) {

}

Panel::~Panel() {

}

void Panel::addControl(Control& c, int x, int y) {
	c.setPosition({ x + GetLeft(), y + getTop() });
	int x1 = c.GetLeft() + c.getText().length();
	int y1 = c.getTop() + 1;
	c.setCursor(x1 + 1, y1);
	_controls.push_back(&c);
	c.setLayer(2);
}

void Panel::getAllControls(vector<Control*> &controls) {
	for (Control* c : _controls) {
		controls.push_back(c);
	}
}

void Panel::draw(Graphics& g, int x, int y, size_t layer) {
		Control::draw(g, x, y, layer);
		for (Control * c : _controls){
			int l = c->getLayer();
			if (l == layer){
				c->draw(g, x, y, layer);
			}
		}
		getFocus()->showCursorOnScreen(g);

}

// Finds control on the given position and sets the focus on it.
void Panel::setFocusByPosition(int x, int y){
	bool found = false;
	int vc_size = this->getControls().size();
	for (size_t p = 5; p >0; --p){ // run of all layers
		for (int j = vc_size - 1; j >= 0; j--) { // run of all controls revers
			if (this->getControls()[j]->getLayer() == p){
				if (this->getControls()[j]->isClicked(x, y)){
					if (this->getControls()[j]->canGetFocus()){
						Control::setFocus(this->getControls()[j]);
						return;
					}
				}
			}
		}
	}
}

void Panel::mousePressed(int x, int y, bool isLeft) {
	setFocusByPosition(x, y);
	Control::getFocus()->mousePressed(x, y, isLeft);
}

void Panel::keyDown(int, char) {

}

bool Panel::canGetFocus() const {
	return false;
}
