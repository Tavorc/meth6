#include "Button.h"

Button::Button(int width) : Control(width) {

}

Button::~Button() {

}

void Button::draw(Graphics& g, int x, int y, size_t layer) {
	//g.setBackground(GetBackgroundColor());
	//g.setForeground(GetForegroundColor());
	Control::draw(g, x, y, layer);
	if (GetBorder() != BorderType::None) g.write(x + GetLeft() + 1, y + getTop() + 1, GetText());
	else g.write(x + GetLeft(), y + getTop(), GetText());
}

void Button::mousePressed(int x, int y, bool isLeft) {
	for (MouseListener *listener : listeners)
		listener->mousePressed(*this,x, y, isLeft);
}

void Button::keyDown(int, char) {

}

bool Button::canGetFocus() const {
	return true;
}


void Button::AddListener(MouseListener &listener){
	listeners.push_back(&listener);
}

void Button::SetText(string value){

}