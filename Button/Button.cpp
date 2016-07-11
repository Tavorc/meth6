#include "Button.h"
// C'tor
Button::Button(int width) : Label(width) {
}
// D'tor
Button::~Button() {
}
// Draw button
void Button::draw(Graphics& g, int x, int y, size_t layer) {
	Control::draw(g, x, y, layer);
	if (getBorder() != BorderType::None) g.write(x + GetLeft() + 1, y + getTop() + 1, getText());
	else g.write(x + GetLeft(), y + getTop(), getText());
}
// Mouse event
void Button::mousePressed(int x, int y, bool isLeft) {
	for (MouseListener *listener : listeners)
		listener->mousePressed(*this, x, y, isLeft);
}
// Key event
void Button::keyDown(int, char) {

}
// is button can get focus
bool Button::canGetFocus() const {
	return false;
}
// is button can be clicked
bool Button::canClicked() const {
	return true;
}
// Add listener to Button
void Button::addListener(MouseListener &listener){
	listeners.push_back(&listener);
}

