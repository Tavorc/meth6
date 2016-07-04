#include "Panel.h"

Panel::Panel() : Control(0), _height(0) {

}

Panel::Panel(int height, int width) : Control(width), _height(height) {

}

Panel::~Panel() {

}

void Panel::AddControl(Control& c, int x, int y) {
	c.SetPosition({ x+GetLeft(), y+getTop() });
	int x1 = c.GetLeft() + c.GetText().length();
	int y1 = c.getTop() + 1;
	c.SetCursor(x1,y1);
	_controls.push_back(&c);
}

void Panel::getAllControls(vector<Control*> &controls) {
	for (Control* c : _controls) {
		controls.push_back(c);
	}
}

void Panel::draw(Graphics& g, int x, int y, size_t layer) {
	Control::draw(g, x, y, layer);
	for (Control * c : _controls) c->draw(g, x, y, layer);
	GetFocus()->showCursorOnScreen(g);
}

// Finds control on the given position and sets the focus on it.
void Panel::setFocusByPosition(int x, int y){
	bool found = false;
	int vc_size = this->GetControls().size();
	for (int j = vc_size - 1; j >= 0; j--) {
		if (this->GetControls()[j]->isClicked(x, y)){
			if (this->GetControls()[j]->canGetFocus()){
				Control::SetFocus(this->GetControls()[j]);
				found = true;
				break;
			}
		}
	}
}

void Panel::mousePressed(int x, int y, bool isLeft) {
	setFocusByPosition(x,y);
	Control::GetFocus()->mousePressed(x, y, isLeft);
}

void Panel::keyDown(int, char) {

}

bool Panel::canGetFocus() const {
	return false;
}
