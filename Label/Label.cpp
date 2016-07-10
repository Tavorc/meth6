#include "Label.h"

Label::Label(int width) : Control(width) {

}

Label::~Label() {

}

void Label::draw(Graphics& g, int x, int y, size_t layer) {
	//g.setBackground(getBackgroundColor());
	//g.setForeground(getForegroundColor());
	Control::draw(g, x, y, layer);
	if (getBorder() != BorderType::None) g.write(x + GetLeft() + 1, y + getTop() + 1, getText());
	else g.write(x + GetLeft(), y + getTop(), getText());
}

void Label::mousePressed(int, int, bool) {

}

void Label::keyDown(int, char) {

}

bool Label::canGetFocus() const {
	return false;
}
