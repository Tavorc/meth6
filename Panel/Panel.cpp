#include "Panel.h"


void updatePosition(Control & child, int x, int y);

// C'tor
Panel::Panel() : Control(0) {

}

// C'tor gets height and width of panel
Panel::Panel(int height, int width) : Control(width) {
	_height = height;
}

// D'tor
Panel::~Panel() {

}

// Gets a control and define its relative position
void Panel::addControl(Control& c, int x, int y) {
	_controls.push_back(&c);
	c.setLayer(getLayer() + 1);
	updatePosition(c, x, y);
}

// Gets control and sets its relative position and its children recursive
void updatePosition(Control & child, int x, int y){
	child.setPosition({ x + child.GetLeft(), y + child.getTop() });
	int x1 = child.GetLeft() + child.getText().length();
	int y1 = child.getTop() + 1;
	child.setCursor(x1 + 1, y1);
	if (dynamic_cast<Panel*>(&child)){
		vector<Control*> v;
		child.getAllControls(v);
		for (Control * c : v){
			updatePosition(*c, x, y);
		}
	}
}

// Sets layer of panel recursively
void Panel::setLayer(size_t layer){
	this->Control::setLayer(layer);
	if (dynamic_cast<Panel*>(this)){
		vector<Control*> v;
		this->getAllControls(v);
		for (Control * c : v){
			c->setLayer(layer + 1);
		}
	}
}

// Sets visability recursively
void Panel::setVisibility(bool isVisible){
	this->Control::setVisibility(isVisible);
	if (dynamic_cast<Panel*>(this)){
		vector<Control*> v;
		this->getAllControls(v);
		for (Control * c : v){
			c->setVisibility(isVisible);
		}
	}
}

// Gets all control of this panel
void Panel::getAllControls(vector<Control*> &controls) {
	for (Control* c : _controls) {
		controls.push_back(c);
	}
}

// Draw panel and its children 
void Panel::draw(Graphics& g, int x, int y, size_t layer) {
	if (this->getVisibility()){
		if (getLayer() == layer){
			Control::draw(g, x, y, layer);
		}
		else{
			for (Control * c : _controls){
				int l = c->getLayer();
				if (l == layer && c->getVisibility()){
					c->draw(g, x, y, layer);
				}
			}
		}
		getFocus()->showCursorOnScreen(g);
	}
}

// Finds control on the given position and sets the focus on it.
void Panel::setFocusByPosition(int x, int y){
	bool found = false;
	int vc_size = this->getControls().size();
	for (size_t p = 5; p >0; --p){ // run of all layers
		for (int j = vc_size - 1; j >= 0; j--) { // run of all controls revers
			Control * c = this->getControls()[j];
			if (c->getLayer() == p){
				if (c->isClicked(x, y) && c->getVisibility()){
					if (c->canGetFocus() || c->canClicked()){
						Control::setFocus(c);
					}
					return;
				}
			}
		}
	}
}

// Mouse event 
void Panel::mousePressed(int x, int y, bool isLeft) {
	setFocusByPosition(x, y);
	Control::getFocus()->mousePressed(x, y, isLeft);
}

// Key event
void Panel::keyDown(int, char) {

}

// Is panel can get focus
bool Panel::canGetFocus() const {
	return false;
}
