#include "Label.h"

Label::Label(int width) : Control(width) {

}

Label::~Label() {

}

void Label::draw(Graphics& g, int x, int y, size_t layer) {
	//g.setBackground(GetBackgroundColor());
	//g.setForeground(GetForegroundColor());
	Control::draw(g, x, y, layer);
	if (GetBorder() != BorderType::None) g.write(x + GetLeft() + 1, y + getTop() + 1, GetText());
	else g.write(x + GetLeft(), y + getTop(), GetText());
}

void Label::mousePressed(int, int, bool) {

}

void Label::keyDown(int, char) {

}

bool Label::canGetFocus() const {
	return false;
}
