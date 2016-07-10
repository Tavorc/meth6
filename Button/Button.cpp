#include "Button.h"

Button::Button(int width) : Control(width) {

}

Button::~Button() {

}

void Button::draw(Graphics& g, int x, int y, size_t layer) {

	Control::draw(g, x, y, layer);
	if (getBorder() != BorderType::None) g.write(x + GetLeft() + 1, y + getTop() + 1, getText());
	else g.write(x + GetLeft(), y + getTop(), getText());
}

void Button::mousePressed(int x, int y, bool isLeft) {
	for (MouseListener *listener : listeners)
		listener->mousePressed(*this, x, y, isLeft);
}

void Button::keyDown(int, char) {

}

bool Button::canGetFocus() const {
	return true;
}


void Button::addListener(MouseListener &listener){
	listeners.push_back(&listener);
}

